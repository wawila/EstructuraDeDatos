#ifndef SEMAFOROGRAFO_H
#define SEMAFOROGRAFO_H

#include <QDialog>
#include <iostream>
#include <QLabel>

using namespace std;

class Calle
{
public:
    QString nombre;
    QString color;
    QList<Calle*> adyacentes;

    Calle(QString nom){ nombre = nom;
                        color = "BLANCO";}
    QList<Calle *> getAdyacente(){ return adyacentes; }
    QString getNombre(){ return nombre; }
    QString getColor() { return color; }

    void setNombre(QString n){ nombre = n; }
    void cambiarColor(QString c){ color = c; }

    ~Calle();
};

namespace Ui {
class SemaforoGrafo;
}

class SemaforoGrafo : public QDialog
{
    Q_OBJECT

public:
    explicit SemaforoGrafo(QWidget *parent = 0);

    Calle* AB;
    Calle* AC;
    Calle* AD;
    Calle* BA;
    Calle* BC;
    Calle* BD;
    Calle* DA;
    Calle* DB;
    Calle* DC;
    Calle* EA;
    Calle* EB;
    Calle* EC;
    Calle* ED;

    QList<QString> colores;
    QList<Calle*> calles;
    QList<Calle*> listo;
    QList<QLabel *> label;

    void pintar();
    void imprimirCalles();
    bool grupoPintado(Calle* calle);

    QList<Calle*> getCalles(){ return calles; }

    ~SemaforoGrafo();

private slots:
    void on_pushPintar_clicked();

private:
    Ui::SemaforoGrafo *ui;
};

#endif // SEMAFOROGRAFO_H
