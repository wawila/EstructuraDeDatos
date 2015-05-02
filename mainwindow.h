#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <fstream>
#include <string>
#include <ordenararreglo.h>
#include <arreglos.h>
#include <apuntadorescartas.h>
#include <semaforografo.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_botonOrdenar_clicked();
    void on_botonArray_clicked();
    void on_botonApuntador_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
