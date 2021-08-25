#ifndef DIALOGWINDOWT9_H
#define DIALOGWINDOWT9_H

#include <QDialog>
#include "phonebook.h"

namespace Ui
{
    class DialogWindowT9;
}

class DialogWindowT9 : public QDialog
{
    Q_OBJECT
    void input_items(const item& new_inf);
    void clear_input_lines();

public slots:
    void set_contacs(const std::map<QString, QString>& contacts)
    {
        m_contacts = contacts;
    }

public:
    explicit DialogWindowT9(QWidget *parent = nullptr);
    ~DialogWindowT9();

    void set_storage(const std::map<QString, QString>& map)
    {
        m_contacts = map;
    }

private slots:
    void on_pushButton_2_ABC_clicked();

    void on_pushButton_3_DEF_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::DialogWindowT9 *ui;
    int m_current_row{ 0 };
    std::map<QString, QString> m_contacts;
};

#endif // DIALOGWINDOWT9_H
