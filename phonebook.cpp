#include "phonebook.h"
#include <algorithm>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <iterator>
#include <memory>
#include <QString>
#include <functional>
#include <string>

using  namespace std::placeholders;


namespace utl_phonebook
{
    item nameNumberToItem(const std::string& info, const std::string& pref)
    {
        int index = info.find(pref);
        std::string name{ info.substr(0, index) };
        std::string number { info.substr(index + pref.size()) };

        return { name.data(), number.data() };
    }
}


QString error_message(Associative_Phonebook::Type_Error type)
{

    switch (type)
    {
       case Associative_Phonebook::Type_Error::CanNotOpenFile :
       return {"Can not open file : -1" };

       case Associative_Phonebook::Type_Error::ReadPastEnd :
       return { "The text stream has read past the end of the data in the underlying device. : 1" };

       case Associative_Phonebook::Type_Error::ReadCorruptData :
       return { "The text stream has read corrupt data. : 2" };

       case Associative_Phonebook::Type_Error::WriteFailed :
       return { "The text stream cannot write to the underlying device. : 3" };

       case Associative_Phonebook::Type_Error::ReadFailed :
       return { "The text stream cannot write to the underlying device. : 4" };
    }

    return {};
}

void Associative_Phonebook::add_contact(const QString& name, const QString& number)
{
   // m_storage[name] = number;
    m_storage.insert( item(name, number) );
}

void Associative_Phonebook::add_contact(const item &new_contact)
{
    m_storage.insert(new_contact);
}

Associative_Phonebook::Type_Error Associative_Phonebook::save(const QString &path)
{
    std::fstream stream_out(path.toStdString(), std::ios_base::out);
    if (!stream_out.is_open())
    {
        return Type_Error::CanNotOpenFile;
    }

    stream_out.exceptions( std::ios_base::failbit | std::ios_base::badbit );

    try
    {   
        std::string pref { m_sep_pref };
        std::transform(m_storage.begin(), m_storage.end(), std::ostream_iterator<std::string>(stream_out, "\n"),
                       [](const item& info)
                       {
                            return info.first.toStdString() + '\n' + info.second.toStdString();
                       });
    }
    catch (const std::ios_base::failure&)
    {
        return Type_Error::WriteFailed;
    }

    return Type_Error::None;
}

Associative_Phonebook::Type_Error Associative_Phonebook::load(const QString &path)
{
    std::fstream stream_in(path.toStdString(), std::ios_base::in);
    if (!stream_in.is_open())
    {
        return Type_Error::CanNotOpenFile;
    }

    stream_in.exceptions(std::ios_base::badbit);

    try
    {       
        while (!stream_in.eof())
        {
            std::string name;
            std::getline(stream_in, name);

            std::string number;
            std::getline(stream_in, number);

            if(!name.empty() || !number.empty())
            {
                m_storage[name.c_str()] = number.c_str();
            }
        }

    }
    catch (std::ios_base::failure&)
    {
        return Type_Error::ReadFailed;
    }

    return Type_Error::None;
}


QString Associative_Phonebook::search(const QString &find_name)
{
    std::map<QString, QString>::iterator searching_iter = m_storage.find(find_name);

    if (searching_iter == m_storage.end())
    {
        return {};
    }

    return { searching_iter->second };
}


