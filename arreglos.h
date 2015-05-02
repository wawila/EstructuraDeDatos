#ifndef ARREGLOS_H
#define ARREGLOS_H

#include <QDialog>
#include <QSpinBox>
#include <Qlabel>
#include <iostream>

using namespace std;

namespace Ui {
class Arreglos;
}

class Arreglos : public QDialog
{
    Q_OBJECT

public:
    int agregados;
    int size;
    int arreglo[15];
    int actual;
    bool insert(int pos, int num);
    int search(int num);
    void clear();
    bool append(int num);
    bool eliminar(int pos);
    void imprimirPantalla();

    explicit Arreglos(QWidget *parent = 0);
    ~Arreglos();

private slots:
    void on_pushAgregar_clicked();
    void on_pushInsertar_clicked();
    void on_pushEliminar_clicked();
    void on_pushBuscar_clicked();
    void on_pushClear_clicked();

private:
    Ui::Arreglos *ui;
};

#endif // ARREGLOS_H
