#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioButton->setText("Светло");
    ui->radioButton_2->setText("Темно");

    ui->comboBox->addItem("Виджеты");
    ui->comboBox->addItem("Дизайнер");
    ui->comboBox->addItem("Объекты");
    ui->comboBox->addItem("Компоненты");

    ui->pushButton->setText("Toggle button");
    ui->pushButton->setCheckable(true); // set as toggle

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setValue(0);

    ui->label->setText("0");
    ui->label_2->setText("10");
    ui->label_3->setText("0%");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    auto p = ui->progressBar;
    auto new_value = p->value() + p->maximum() * 0.1;

    if (new_value > p->maximum())
        p->setValue(p->minimum());
    else
        p->setValue(new_value);

    ui->label_3->setText(QString::number(p->value() * 100 / p->maximum()) + "%");
}

