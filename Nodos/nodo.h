#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <QCoreApplication>
#include <QPushButton>
#include <QDebug>
using namespace std;



class nodo
{
public:
    nodo(int num, int x, int y, QWidget* q);
    int numero;
    int enX;
    int enY;
    bool eliminado;
    QPushButton *boton;
     nodo *sig;
     void cambiarPosicion(int a, int b);
};

#endif // NODO_H
