#include "listanodo.h"
#include <iostream>

using namespace std;


listanodo::listanodo()
{
    cantEmpleados=0;
    totalSalarios=0;
    mayor=0;
    menor=0;
    inicial=0;
    temporal=0;
}

void listanodo::addNodo(nodo* n)
{
    if(inicial==0)
        inicial=n;
    else
    {
        temporal=inicial;
        while(temporal->sig!=0)
            temporal=temporal->sig;
        temporal->sig=n;
    }
    actualizarLista();

}
void listanodo::actualizarLista()
{
    totalSalarios=0;
    cantEmpleados=0;
    temporal=inicial;
    mayor=temporal->numero;
    menor=temporal->numero;
    if(temporal->sig==0 && !temporal->eliminado)
        temporal->boton->show();

       while(temporal->sig!=0)
           {

           if(!temporal->eliminado)
           {
               qDebug()<<temporal->numero;
           cantEmpleados++;
           temporal->boton->show();
           totalSalarios+=temporal->numero;
           temporal=temporal->sig;
            if(temporal->numero<menor)
                menor=temporal->numero;
            if(temporal->numero>mayor)
                mayor=temporal->numero;
           }
          }
       if(!temporal->eliminado)
       {
           qDebug()<<temporal->numero;
        temporal->boton->show();
        cantEmpleados++;
       }

       totalSalarios+=temporal->numero;
          // temporal=temporal->sig;

}
void listanodo::eliminarNodo(int num)
{

    if(num==1)
    {
        inicial->eliminado=true;
        inicial->boton->hide();
        elementox=0;
        elementoy=55;
        inicial=inicial->sig;

        reacomodar(num,sumaEmpleados());
        actualizarLista();
        return;
    }

    temporal=inicial;

    for(int x=0; x<(1-num); x++)
    {
        temporal=temporal->sig;
    }
    elementox=temporal->sig->enX;
    elementoy=temporal->sig->enY;
    qDebug()<<"Borrando Nodo"<<temporal->sig->numero<<"posx"<<temporal->sig->enX<<"posy"<<temporal->sig->enY;
    temporal->sig->eliminado=true;

    temporal->sig=temporal->sig->sig;
       actualizarLista();
       qDebug()<<"Reacomodar!";
        reacomodar(num,sumaEmpleados());
        return;

}

void listanodo::crearNodo(int s,int x, int y, QWidget* q)
{
    nodo * no= new nodo(s, x, y, q);
    addNodo(no);

}

double listanodo::promedioSalario()
{
    actualizarLista();
    return (totalSalarios/cantEmpleados);
}

int listanodo::sumaEmpleados()
{
    actualizarLista();
    return cantEmpleados;
    //return 1;

}

double listanodo::salarioMayor()
{
    actualizarLista();
    return mayor;

}

double listanodo::salarioMenor()
{
    actualizarLista();
    return menor;

}

double listanodo::sumaSalarios()
{
    actualizarLista();
    return totalSalarios;
}

void listanodo::reacomodar(int x, int veces)
{
    qDebug() << "principio"<<veces;

    temporal=inicial;
    qDebug()<<temporal->numero;
    --x;
    for(int y=0; y<x;y++)
    {
        qDebug() << "4"<<"p"<<x;

        temporal=temporal->sig;

    }

    bool flag=true;
    qDebug() <<"*"<<temporal->numero;


   for(int e=x; e<veces;e++)
   {    qDebug() << "5\n"<<"numero"<<temporal->numero;

      //temporal->cambiarPosicion(this->elementox, this->eleme<<ntoy);
       temporal->boton->move(elementox,elementoy);
       qDebug()<<"numero"<<temporal->numero<<this->elementox<<this->elementoy;
    if(flag)
     elementox+=55;
    else
        elementox-=55;

     if(elementox==715)
      {
        flag=false;
        elementoy+=55;
      }

     if(elementox==0)
      {
         flag=true;
         elementoy+=55;
      }
     temporal=temporal->sig;
   }
   qDebug() << "6";
        elementox-=55;


}
