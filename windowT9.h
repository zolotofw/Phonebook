#ifndef WINDOWT9_H
#define WINDOWT9_H

#include <QMainWindow>
#include "phonebook.h"

namespace Ui {
class WindowT9;
}

class WindowT9 : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowT9(QWidget *parent = nullptr);
    ~WindowT9();
    void set_storage(const std::map<QString, QString>& map)
    {
        m_contacts = map;
    }

    void input_items(const item& info);


private slots:
    void on_pushButton_2_ABC_clicked();

private:
    Ui::WindowT9 *ui;
    std::map<QString, QString> m_contacts;
    int m_current_row{ 0 };
};

#endif // WINDOWT9_H
