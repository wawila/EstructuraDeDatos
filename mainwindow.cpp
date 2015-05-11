#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

void MainWindow::on_pushButton_clicked()
{
    cout<<"Se apreto el boton: Semaforo"<<endl;
    SemaforoGrafo window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_botonOrdenar_clicked()
{
    cout<<"Se apreto el Boton: Ordenar Arreglo"<<endl;
    OrdenarArreglo window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_botonArray_clicked()
{
    cout<<"Se apreto el Boton: Array"<<endl;
    Arreglos window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_botonApuntador_clicked()
{
    cout<<"Se apreto el Boton: Apuntador"<<endl;
    ApuntadoresCartas window;
    window.setModal(true);
    window.exec();

}

void MainWindow::on_botonPilas_clicked()
{
    cout<<"Se apreto el Boton: Pilas"<<endl;
    Pilas window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_botonColas_clicked()
{
    cout<<"Se apreto el Boton: Colas"<<endl;
    Colas window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_botonCursores_clicked()
{
    cout<<"Se apreto el Boton: Cursores"<<endl;
    Cursores window;
    window.setModal(true);
    window.exec();
}
