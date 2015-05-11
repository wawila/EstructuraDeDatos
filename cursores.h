#ifndef CURSORES_H
#define CURSORES_H

#include <QDialog>
#include <iostream>
#include <Qlabel>
#include <QSpinBox>

class Cursor
{
public:
    Cursor()
    {

    }

    Cursor(QString valor, int sig)
    {
        this->valor = valor;
        this->sig = sig;
    }

    QString valor;
    int sig;
};

namespace Ui {
class Cursores;
}

class Cursores : public QDialog
{
    Q_OBJECT

public:
    int size;
    int inicio[10];
    Cursor espacio[10];
    void agregar(int lista, QString valor);
    void insertar(int lista, QString valor, int pos);
    void eliminar(int lista, int pos);
    int getAnterior(int lista, QString valor);
    int buscar(int lista, QString valor);
    void inicializar();
    void crearLista(QString valor);
    explicit Cursores(QWidget *parent = 0);
    ~Cursores();



private:
    Ui::Cursores *ui;
};

#endif // CURSORES_H
