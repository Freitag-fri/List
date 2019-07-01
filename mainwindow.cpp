#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <list.cpp>
//void ChoiceList(int n, int q, int pos);
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
    ui->comboBox->addItem("Insert");        //4     добавление элемента на позицию
    ui->comboBox->addItem("Erase");         //5
    ui->comboBox->addItem("Size");          //6
    //ui->comboBox->addItem("Clear");         //5
    b.push_back(5);
    b.push_back(10);
    b.push_back(15);
    b.push_back(20);

    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));    //возможность вписывать только цифры
    ui->position->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    int n = ui->lineEdit->text().toInt();               //добавляемый элемент
    int pos = ui->position->text().toInt();             //позиция
    int operation = ui->comboBox->currentIndex();       //комманда для выполнения
    ChoiceList(operation, n, pos);
    ui->textEdit->clear();                              //очистка поля

    if (operation == 6)
        ui->textEdit->insertPlainText(QString::number(b.GetSize()));
    else
    {
        for (int i = 0; i < b.GetSize(); i++)
        {
            ui->textEdit->insertPlainText(QString::number(b[i]));
            ui->textEdit->insertPlainText(" ");
        }
    }

}
void MainWindow::ChoiceList(int n, int q, int pos)
{
    if (n == 0 || n == 1)
    {
        if(ui->lineEdit->text() == "")
        {
         QMessageBox::information(NULL,QObject::tr("Информация"),tr("Введите данные"));
         return;
        }
    }
    if( n == 4 && (ui->lineEdit->text() == "" || ui->position->text() == ""))
    {
     QMessageBox::information(NULL,QObject::tr("Информация"),tr("Введите данные или позицию"));
     return;
    }

    if (n == 0)
        b.push_back(q);

    else if (n == 1)
        b.push_front(q);

    else if (n == 2)
        b.pop_back();

    else if(n == 3)
        b.pop_front();

    else if(n == 4)
        b.insert(pos, q);

    else if(n == 5)
        b.Erase(pos);

//    else if(n == 5)
//        b.clear();
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    int oper = ui->comboBox->currentIndex();

    if(oper != 4 && oper != 5)
     {
       ui->position->clear();
       ui->position->setFocusPolicy(Qt::NoFocus);
       ui->label_2->setText("Position ");
     }

     if(oper == 4 || oper == 5)
     {
       ui->position->setFocusPolicy(Qt::StrongFocus);
       ui->label_2->setText("Position*");
     }


     if (oper == 6 || oper == 2 || oper == 3 || oper == 5)
     {
         ui->lineEdit->clear();
         ui->lineEdit->setFocusPolicy(Qt::NoFocus);
         ui->label->setText("Data ");
     }

     if (oper == 0 || oper == 1|| oper == 4)
     {
         ui->lineEdit->setFocusPolicy(Qt::StrongFocus);
         ui->label->setText("Data* ");
     }
}
