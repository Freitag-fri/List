#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <list.cpp>
void ChoiceList(int n, int q);
List b;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Push_back");     //0
    ui->comboBox->addItem("Push_front");    //1
    ui->comboBox->addItem("Pop_back");      //2
    ui->comboBox->addItem("Pop_front");     //3
    b.push_back(5);
    b.push_back(10);
    b.push_back(15);
    b.push_back(20);
    b.push_back(25);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int n = ui->lineEdit->text().toInt();
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ChoiceList(ui->comboBox->currentIndex(), n);    //определение опперации, вводимое число
    ui->textEdit->clear();                          //очистка поля

    for (int i = 0; i < b.GetSize(); i++)
    {
        ui->textEdit->insertPlainText(QString::number(b[i]));
        ui->textEdit->insertPlainText(" ");
    }

}
void ChoiceList(int n, int q)
{

    if (n == 0)
        b.push_back(q);

    else if (n == 2)
        b.pop_back();

    else if(n == 3)
        b.pop_front();

}
