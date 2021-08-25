#include "solutionT9.h"
#include <QString>
#include <unordered_map>
#include <functional>
#include <algorithm>

using std::map;
using namespace std::placeholders;

namespace utils_T9
{
    using item  = std::pair<QString, QString>;

    std::map<QChar, QString> storage_t9{
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
    };

    bool checkingChar(QChar v_contact, QChar v_t9)
    {              
        return v_contact.toLower() == v_t9 || v_contact == v_t9;
    }

    bool matchingT9(QChar v_name, QChar v_t9)
    {
        QString str_t9 = storage_t9[v_t9];

        return std::any_of(str_t9.begin(), str_t9.end(), std::bind(checkingChar, v_name, _1));
    };


    bool checkMatches(const QString& contact, const QString& num )
    {
        int index_space = contact.indexOf(' ');

        QString name(contact.data(), num.size());

        bool check = std::equal(name.begin(), name.end(), num.begin(), matchingT9);

        if(!check && index_space > 0)
        {
            ++index_space;
            QString surname(contact.data() + index_space, num.size());
            check =  std::equal(surname.begin(),surname.end(), num.begin(), matchingT9);
        }

        return check;
    }

}


namespace T9
{
    map<QString, QString>matchesT9(const map<QString, QString>& contacts, const QString& numbers )
    {
        map<QString, QString> results;

        for(auto begin = contacts.begin(), end = contacts.end(); begin != end; ++begin)
        {
            QString name = begin->first;

            if(utils_T9::checkMatches(name, numbers))
            {
                results[name] = begin->second;
            }
        }

        return results;
    }
}
