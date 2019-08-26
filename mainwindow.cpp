#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <list.cpp>


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
    ui->comboBox->addItem("Clear");         //8
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

    if (operation == b.OpSize)
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
    if (oper == b.OpPush_back || oper == b.OpPush_front)
    {
        if(ui->ListData->text() == "")
        {
            QMessageBox::information(NULL,QObject::tr("Информация"),tr("Введите данные"));
            return;
        }
    }
    else if(oper == b.OpInsert && (ui->ListData->text() == "" || ui->position->text() == ""))
    {
        QMessageBox::information(NULL,QObject::tr("Информация"),tr("Введите данные или позицию"));
        return;
    }
    else if(oper == b.OpErase && ui->position->text() == "")
    {
        QMessageBox::information(NULL,QObject::tr("Информация"),tr("Позицию для удаления"));
        return;
    }


    if (oper == b.OpPush_back)
        b.push_back(data);

    else if (oper == b.OpPush_front)
        b.push_front(data);

    else if (oper == b.OpPop_back)
        b.pop_back();

    else if(oper == b.OpPop_front)
        b.pop_front();

    else if(oper == b.OpInsert)
        b.insert(pos, data);

    else if(oper == b.OpErase)
        b.Erase(pos);

    else if(oper == b.OpSave)
        b.Save();

    else if(oper == b.OpClear)
        b.clear();
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    int index = ui->comboBox->currentIndex();

    if(index != b.OpInsert && index != b.OpErase)
    {
        ui->position->clear();
        ui->position->setFocusPolicy(Qt::NoFocus);
        ui->label_2->setText("Position ");
    }

    if(index == b.OpInsert || index == b.OpErase)
    {
        ui->position->setFocusPolicy(Qt::StrongFocus);
        ui->label_2->setText("Position*");
    }


    if (index == b.OpSize || index == b.OpPop_back || index == b.OpPop_front || index == b.OpErase || index == b.OpClear)
    {
        ui->ListData->clear();
        ui->ListData->setFocusPolicy(Qt::NoFocus);
        ui->label->setText("Data ");
    }

    if (index == b.OpPush_back || index == b.OpPush_front|| index == b.OpInsert)
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
