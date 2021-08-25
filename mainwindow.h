#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "phonebook.h"


QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void input_items(const item& new_inf);
    void clear_input_lines();

signals :
    void set_print_T9(const QString& setT9, const std::map<QString, QString>& storage);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void get_print_T9(const QString& setT9, const std::map<QString, QString>& storage);

private slots:
    void on_Button_Add_contact_clicked();

    void on_Button_Save_phonebook_clicked();

    void on_Button_Load_clicked();

    void on_Button_Clear_table_clicked();

    void on_Button_Find_clicked();

    void on_pushButton_2_ABC_clicked();

    void on_pushButton_3_DEF_clicked();

    void on_pushButton_4_GHI_clicked();

    void on_pushButton_5_JKL_clicked();

    void on_pushButton_6_MNO_clicked();

    void on_pushButton_7_PQRS_clicked();

    void on_pushButton_8_TUV_clicked();

    void on_pushButton_9_WXYZ_clicked();

    void on_pushButton_ClearT9_clicked();

private:
    Ui::MainWindow *ui;
    int m_current_row = 0;
    Associative_Phonebook m_test_map;
    std::map<QString, QString> m_storageT9;
    QString m_str_T9;
};
#endif // MAINWINDOW_H
