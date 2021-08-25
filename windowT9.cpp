#include "windowT9.h"
#include "ui_windowT9.h"

WindowT9::WindowT9(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowT9)
{
    ui->setupUi(this);

    ui->setupUi(this);
    const int width_col = 230;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0, width_col);
    ui->tableWidget->setColumnWidth(1, width_col);
    ui->tableWidget->setHorizontalHeaderLabels({"Full name :", "Phone number :"});
}

void WindowT9::input_items(const item& info)
{
    QTableWidgetItem* items[2] { new QTableWidgetItem(info.first),
                                 new QTableWidgetItem(info.second) };

    int colms = 0;
    ui->tableWidget->setRowCount(m_current_row + 1);
    ui->tableWidget->setItem(m_current_row, colms++, items[0]);
    ui->tableWidget->setItem(m_current_row, colms++, items[1]);
    ++m_current_row;
    item temp {"name", "267"};
    m_contacts["name"] = "267";
    //delete [] items;
}

WindowT9::~WindowT9()
{
    delete ui;
}

void WindowT9::on_pushButton_2_ABC_clicked()
{
    for (const item& info : m_contacts)
    {
        input_items(info);
    }
}
