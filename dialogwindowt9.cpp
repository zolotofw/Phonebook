#include "dialogwindowt9.h"
#include "ui_dialogwindowt9.h"

DialogWindowT9::DialogWindowT9(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWindowT9)
{

    ui->setupUi(this);
    connect(ui->pushButton_2_ABC, SIGNAL(clicked()), this, SLOT(on_pushButton_2_ABC_clicked()));
    const int width_col = 230;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0, width_col);
    ui->tableWidget->setColumnWidth(1, width_col);
    ui->tableWidget->setHorizontalHeaderLabels({"Full name :", "Phone number :"});
}

void DialogWindowT9::input_items(const item& info)
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

DialogWindowT9::~DialogWindowT9()
{
    delete ui;
}

void DialogWindowT9::on_pushButton_2_ABC_clicked()
{
    this->close();
}

void DialogWindowT9::on_pushButton_3_DEF_clicked()
{
    for (const item& info : m_contacts)
    {
        input_items(info);
    }

}

void DialogWindowT9::on_lineEdit_returnPressed()
{
    m_contacts["lol"] = ui->lineEdit->text();
    for (const item& info : m_contacts)
    {
        input_items(info);
    }
}
