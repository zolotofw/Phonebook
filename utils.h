#ifndef UTILS_H
#define UTILS_H
#include <QString>

struct Contact
{   
    QString name;
    QString number;

    bool is_empty();
    bool operator ==(const Contact& another);
};

Contact binary_search(const QString& str, const QVector<Contact>& storage);

#endif // UTILS_H
