#ifndef PILAS_H
#define PILAS_H

#include <QDialog>
#include <iostream>
#include <Qlabel>
#include <QSpinBox>

using namespace std;

class NodoPila
{
public:
    int valor;
    NodoPila* anterior;

    NodoPila(int v)
    {
        valor = v;
    }
};

namespace Ui {
class Pilas;
}

class Pilas : public QDialog
{
    Q_OBJECT

public:
    NodoPila* tope;
    int size;
    explicit Pilas(QWidget *parent = 0);
    ~Pilas();
    NodoPila* getTope();
    bool sacar();
    void meter(NodoPila* nodo);
    bool isVacia();
    void anular();
    void imprimir();

private slots:
        void on_pushMeter_clicked();
        void on_pushAnular_clicked();
        void on_pushVacia_clicked();
        void on_pushTope_clicked();
        void on_pushSacar_clicked();

private:
    Ui::Pilas *ui;
};

#endif // PILAS_H
