#ifndef LISTANODO_H
#define LISTANODO_H
#include "nodo.h"
#include <QDebug>

using namespace std;


class listanodo
{
public:
    listanodo();
    int cantEmpleados;
    double totalSalarios;
    double mayor;
    double menor;
    int elementox=-55;
    int elementoy=0;

    nodo * temporal;
    nodo * inicial;
    void addNodo(nodo * n);
    void crearNodo(int s, int x, int y, QWidget* q);
    void actualizarLista();
    void eliminarNodo(int num);
    double promedioSalario();
    int sumaEmpleados();
    void reacomodar(int x, int veces);
    double salarioMayor();
    double salarioMenor();
    double sumaSalarios();


};

#endif // LISTANODO_H
