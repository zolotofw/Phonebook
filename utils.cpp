#include "utils.h"
#include <QVector>


bool Contact::is_empty()
{
    return (name.isEmpty() || number.isEmpty());
}

bool Contact::operator==(const Contact& another)
{
    return (name == another.name || number == another.number);
}

Contact binary_search(const QString& str, const QVector<Contact>& storage)
{
    if(storage.isEmpty())
    {
        return { "not found", "not found" };
    }

    int middle = storage.size() / 2;
    QString compare = storage[middle].name;

    if(str == compare)
    {
       return storage[middle];
    }

    if(str > compare)
    {
        return binary_search(str, { storage.begin() + middle, storage.end() });
    }
    else
    {
        return binary_search(str, { storage.begin(), storage.begin() + middle });
    }
}
