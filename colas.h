#ifndef COLAS_H
#define COLAS_H

#include <QDialog>
#include <iostream>
#include <Qlabel>
#include <QSpinBox>

using namespace std;

class NodoCola
{
public:
    int valor;
    NodoCola* anterior;

    NodoCola(int v)
    {
        valor = v;
    }
};

namespace Ui {
class Colas;
}

class Colas : public QDialog
{
    Q_OBJECT

public:
    int size;
    NodoCola* frente;
    NodoCola* ultimo;
    explicit Colas(QWidget *parent = 0);
    bool quitarDeCola();
    void ponerEnCola(NodoCola* n);
    bool isVacia();
    NodoCola* getFrente();
    void anular();
    void imprimir();
    ~Colas();

private slots:
        void on_pushPoner_clicked();
        void on_pushAnular_clicked();
        void on_pushVacia_clicked();
        void on_pushFrente_clicked();
        void on_pushQuitar_clicked();

private:
    Ui::Colas *ui;
};

#endif // COLAS_H
