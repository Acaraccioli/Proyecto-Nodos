#include "nodo.h"
#include <iostream>

using namespace std;
nodo::nodo(int num, int x, int y, QWidget* q)
{
    this->numero=num;
    this->eliminado=false;
    this->boton= new QPushButton(QString::number(num),q);
    this->boton->setGeometry(QRect(QPoint(x, y),QSize(50, 50)));

    this->enX=x;
    this->enY=y;

    this->sig=0;

}
void nodo::cambiarPosicion(int a, int b)
{
    qDebug() << "7";
    //this->boton->setGeometry(QRect(QPoint(a, b),QSize(50,50)));
    this->boton->move(a,b);
}
