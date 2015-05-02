#ifndef APUNTADORESCARTAS_H
#define APUNTADORESCARTAS_H

#include <QDialog>
#include <QSpinBox>
#include <Qlabel>
#include <iostream>

class Cartas
{
public:
    int numero;
    Cartas* sig;
    Cartas(int num)
    {
        numero = num;
    }
};

namespace Ui {
class ApuntadoresCartas;
}

class ApuntadoresCartas : public QDialog
{
    Q_OBJECT

public:
    explicit ApuntadoresCartas(QWidget *parent = 0);
    ~ApuntadoresCartas();

    Cartas* final;
    Cartas* inicio;
    int size;
    void agregar(int num);
    void insertar(int pos, int num);
    Cartas* getFinal();
    void eliminar(int pos);
    Cartas* getPos(int pos);
    Cartas* buscar(int num);
    void imprimirPantalla();

private slots:
    void on_pushAgregar_clicked();
    void on_pushInsertar_clicked();
    void on_pushEliminar_clicked();
    void on_pushBuscar_clicked();

private:
    Ui::ApuntadoresCartas *ui;
};


#endif // APUNTADORESCARTAS_H
