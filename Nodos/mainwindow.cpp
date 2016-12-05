#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QCoreApplication>
#include <QPushButton>
#include <QDebug>


using namespace std;\
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_btn1_clicked()
{
   if(flag)
    lista->elementox+=55;
   else
       lista->elementox-=55;

    if(lista->elementox==715)
     {
       flag=false;
       lista->elementoy+=55;
     }

    if(lista->elementox==0)
     {
        flag=true;
        lista->elementoy+=55;
     }

    int salario = ui->ingresar2->text().toInt();
    lista->crearNodo(salario, lista->elementox, lista->elementoy, this);
    /*prueba
    lista->crearNodo(4,0, lista->elementoy, this);
    lista->crearNodo(3,55, lista->elementoy, this);
    lista->crearNodo(2,110, lista->elementoy, this);
    lista->crearNodo(1,165, lista->elementoy, this);*/

    ui->set1->setText(QString::number(lista->promedioSalario()));
    ui->set2->setText(QString::number(lista->sumaEmpleados()));
    ui->set3->setText(QString::number(lista->salarioMayor()));
    ui->set4->setText(QString::number(lista->salarioMenor()));
    ui->set5->setText(QString::number(lista->sumaSalarios()));



}

void MainWindow::on_btn2_clicked()
{
    int eli = ui->ingresar4->text().toInt();

    lista->eliminarNodo(eli);
    ui->set1->setText(QString::number(lista->promedioSalario()));
    ui->set2->setText(QString::number(lista->sumaEmpleados()));
    ui->set3->setText(QString::number(lista->salarioMayor()));
    ui->set4->setText(QString::number(lista->salarioMenor()));
    ui->set5->setText(QString::number(lista->sumaSalarios()));

}
