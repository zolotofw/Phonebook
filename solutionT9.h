#ifndef SOLUTIONT9_H
#define SOLUTIONT9_H
#include <map>
#include <QString>

using std::map;

namespace utils_T9
{
    using item  = std::pair<QString, QString>;

    bool checkingChar(QChar v_contact, QChar v_t9);

    bool matchingT9(QChar v_name, QChar v_t9);

    bool checkMatches(const QString& contact, const QString& num );
}

namespace T9
{
    map<QString, QString>matchesT9(const map<QString, QString>& contacts, const QString& numbers );
}

#endif // SOLUTIONT9_H
