#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include "solutionT9.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    const int width_col = 230;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0, width_col);
    ui->tableWidget->setColumnWidth(1, width_col);
    ui->tableWidget->setHorizontalHeaderLabels({"Full name :","Phone number :"});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::input_items(const item& info)
{
    QTableWidgetItem* items[2]{ new QTableWidgetItem(info.first),
                                new QTableWidgetItem(info.second)};

    int colms = 0;
    ui->tableWidget->setRowCount(m_current_row + 1);
    ui->tableWidget->setItem(m_current_row, colms++, items[0]);
    ui->tableWidget->setItem(m_current_row, colms++, items[1]);
    ++m_current_row;

    //delete [] items;
}

void MainWindow::clear_input_lines()
{
    ui->Full_name->clear();
    ui->Phone_number->clear();
}

void MainWindow::on_Button_Add_contact_clicked()
{
    const QString& name = ui->Full_name->text();
    const QString& number = ui->Phone_number->text();

    m_test_map.add_contact(name, number);
    input_items({ name, number });
    clear_input_lines();
}

void MainWindow::on_Button_Save_phonebook_clicked()
{
    QString path_save = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text files (*.txt)"));
    Associative_Phonebook::Type_Error state = m_test_map.save(path_save);

    if (state != Associative_Phonebook::Type_Error::None)
    {
        QMessageBox msg_box(QMessageBox::Critical, "Error", error_message(state));
        msg_box.exec();
    }
}

void MainWindow::on_Button_Load_clicked()
{
    on_Button_Clear_table_clicked();
    QString path_load = QFileDialog::getOpenFileName(this, tr("Open File"), "contacts", tr("Text files (*.txt)"));

    Associative_Phonebook::Type_Error state = m_test_map.load(path_load);

    if (state != Associative_Phonebook::Type_Error::None)
    {     
        QMessageBox msg_box(QMessageBox::Critical, "Error", error_message(state));
        msg_box.exec();
    }
    else
    {
        for (const item& info : m_test_map.get_storage())
        {
            input_items(info);
        }
    }
}

void MainWindow::on_Button_Clear_table_clicked()
{
    ui->tableWidget->clearContents();
    m_current_row = 0;
}

void MainWindow::on_Button_Find_clicked()
{
    QString find = ui->Find->text();
    QString result = m_test_map.search(find);

    if (result.isEmpty())
    {
        ui->Edit_number->setText("not found");
        return ;
    }

    ui->Edit_number->setText(result);
}

void MainWindow::get_print_T9(const QString& setT9, const std::map<QString, QString>& storage)
{
    ui->lineEdit_T9->setText(setT9);

    m_storageT9 = T9::matchesT9(storage, setT9);

    on_Button_Clear_table_clicked();

    for (const item& info : m_storageT9)
    {
        input_items(info);
    }
}

void MainWindow::on_pushButton_2_ABC_clicked()
{
    m_str_T9.push_back('2');
    ui->lineEdit_T9->setText(m_str_T9);

    get_print_T9(m_str_T9, m_test_map.get_storage());
}

void MainWindow::on_pushButton_3_DEF_clicked()
{
    m_str_T9.push_back('3');
    ui->lineEdit_T9->setText(m_str_T9);

    get_print_T9(m_str_T9, m_test_map.get_storage());
}

void MainWindow::on_pushButton_4_GHI_clicked()
{
    m_str_T9.push_back('4');
    ui->lineEdit_T9->setText(m_str_T9);

    get_print_T9(m_str_T9, m_test_map.get_storage());
}

void MainWindow::on_pushButton_5_JKL_clicked()
{
    m_str_T9.push_back('5');
    ui->lineEdit_T9->setText(m_str_T9);

    get_print_T9(m_str_T9, m_test_map.get_storage());
}

void MainWindow::on_pushButton_6_MNO_clicked()
{
    m_str_T9.push_back('6');
    ui->lineEdit_T9->setText(m_str_T9);

    get_print_T9(m_str_T9, m_test_map.get_storage());
}

void MainWindow::on_pushButton_7_PQRS_clicked()
{
    m_str_T9.push_back('7');
    ui->lineEdit_T9->setText(m_str_T9);

    get_print_T9(m_str_T9, m_test_map.get_storage());
}

void MainWindow::on_pushButton_8_TUV_clicked()
{
    m_str_T9.push_back('8');
    ui->lineEdit_T9->setText(m_str_T9);

    get_print_T9(m_str_T9, m_test_map.get_storage());
}

void MainWindow::on_pushButton_9_WXYZ_clicked()
{
    m_str_T9.push_back('9');
    ui->lineEdit_T9->setText(m_str_T9);

    get_print_T9(m_str_T9, m_test_map.get_storage());
}

void MainWindow::on_pushButton_ClearT9_clicked()
{
    ui->lineEdit_T9->clear();
    m_str_T9.clear();
}
