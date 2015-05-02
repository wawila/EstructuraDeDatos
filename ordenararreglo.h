#ifndef ORDENARARREGLO_H
#define ORDENARARREGLO_H

#include <QDialog>
#include <iostream>
#include <QSpinBox>
#include <QLabel>

using namespace std;

namespace Ui {
class OrdenarArreglo;
}

class OrdenarArreglo : public QDialog
{
    Q_OBJECT

public:
    int array[10];
    int cont;
    int array_size;
    int ordenado[];
    int borrados;
    explicit OrdenarArreglo(QWidget *parent = 0);
    ~OrdenarArreglo();
    void deleteIndex(int pos, int array[]);
    void llenarArray(string a);

private slots:
        void on_pushOrdenar_clicked();
        void on_agregarArray_clicked();

private:
    Ui::OrdenarArreglo *ui;
};

#endif // ORDENARARREGLO_H
