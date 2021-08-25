#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "utils.h"
#include <QVector>
#include <map>


using item = std::pair<QString, QString>;


namespace utl_phonebook
{
    item nameNumberToItem(const std::string& info, const std::string& pref);    
}

class Associative_Phonebook
{
public :
    enum class Type_Error
    {
        None,
        CanNotOpenFile,
        ReadPastEnd ,
        ReadCorruptData,
        WriteFailed,
        ReadFailed
    };

    void add_contact(const QString& name, const QString& number);
    void add_contact(const item& new_contact);
    Type_Error save(const QString& path);
    Type_Error load(const QString& path);
    QString search(const QString& find_name);
    std::map<QString, QString> get_storage()
    {
        return { m_storage };
    }

private :
    std::map<QString, QString> m_storage;
    const std::string m_sep_pref{" tel:"};
};

QString error_message(Associative_Phonebook::Type_Error type);

#endif // PHONEBOOK_H
