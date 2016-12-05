#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "listanodo.h"
#include <QtCore>



#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    listanodo *lista= new listanodo();

   bool flag=true;
    ~MainWindow();

private slots:
    void on_btn1_clicked();

    void on_btn2_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
