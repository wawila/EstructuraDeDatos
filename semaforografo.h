#ifndef SEMAFOROGRAFO_H
#define SEMAFOROGRAFO_H

#include <QDialog>
#include <vector>
#include <iostream>
#include <QLabel>

using namespace std;

class Calle
{
public:
    QString nombre;
    QString color;
    vector<Calle*> adyacentes;

    Calle(QString nom){ nombre = nom; }
    QString getNombre(){ return nombre; }
    vector<Calle *> getAdyacente(){ return adyacentes; }
    QString getColor() { return color; }
    void cambiarColor(QString c){ color = c; }
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
    vector<Calle*> calles;
    vector<QLabel *> label;

    void pintar();


    ~SemaforoGrafo();

private slots:
    void on_pushPintar_clicked();

private:
    Ui::SemaforoGrafo *ui;
};

#endif // SEMAFOROGRAFO_H
