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
    ui->comboBox->addItem("Save");          //7
    //ui->comboBox->addItem("Clear");         //5
    b.push_back(5);
    b.push_back(10);
    b.push_back(15);
    b.push_back(20);

    ui->ListData->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));    //возможность вписывать только цифры
    ui->position->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    int n = ui->ListData->text().toInt();               //добавляемый элемент
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
void MainWindow::ChoiceList(int oper, int data, int pos)
{
    if (oper == 0 || oper == 1)
    {
        if(ui->ListData->text() == "")
        {
            QMessageBox::information(NULL,QObject::tr("Информация"),tr("Введите данные"));
            return;
        }
    }
    else if(oper == 4 && (ui->ListData->text() == "" || ui->position->text() == ""))
    {
        QMessageBox::information(NULL,QObject::tr("Информация"),tr("Введите данные или позицию"));
        return;
    }
    else if(oper == 5 && ui->position->text() == "")
    {
        QMessageBox::information(NULL,QObject::tr("Информация"),tr("Позицию для удаления"));
        return;
    }


    if (oper == 0)
        b.push_back(data);

    else if (oper == 1)
        b.push_front(data);

    else if (oper == 2)
        b.pop_back();

    else if(oper == 3)
        b.pop_front();

    else if(oper == 4)
        b.insert(pos, data);

    else if(oper == 5)
        b.Erase(pos);

    else if(oper == 7)
        b.Save();

    //    else if(n == 5)
    //        b.clear();
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    int index = ui->comboBox->currentIndex();

    if(index != 4 && index != 5)
    {
        ui->position->clear();
        ui->position->setFocusPolicy(Qt::NoFocus);
        ui->label_2->setText("Position ");
    }

    if(index == 4 || index == 5)
    {
        ui->position->setFocusPolicy(Qt::StrongFocus);
        ui->label_2->setText("Position*");
    }


    if (index == 6 || index == 2 || index == 3 || index == 5)
    {
        ui->ListData->clear();
        ui->ListData->setFocusPolicy(Qt::NoFocus);
        ui->label->setText("Data ");
    }

    if (index == 0 || index == 1|| index == 4)
    {
        ui->ListData->setFocusPolicy(Qt::StrongFocus);
        ui->label->setText("Data* ");
    }
}


void List::Save()
{
    string file = "myFile.txt";
    fstream fs;
    fs.open(file, fstream::in | fstream::out | fstream::app);
    if (fs.is_open())
    {
        for (int i = 0; i < b.GetSize(); i++)
        {
            fs << b[i] << " ";
        }
    }
    fs.close();
}
