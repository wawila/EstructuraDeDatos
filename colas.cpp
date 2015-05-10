#include "colas.h"
#include "ui_colas.h"

Colas::Colas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Colas)
{
    ui->setupUi(this);
    frente = NULL;
    ultimo = NULL;
    size = 0;

    ui->pushVacia->setVisible(false);
    ui->pushFrente->setVisible(false);
    ui->isVacia->setText("Vacia");
    ui->valorFrente->setText("NULL");
}

bool Colas::quitarDeCola()
{
    if(frente && size > 0)
    {
        NodoCola* temp = frente;
        frente = frente->anterior;
        delete temp;
        size--;
        return true;
    }
    return false;
}

void Colas::ponerEnCola(NodoCola *n)
{
    if(frente == NULL)
    {
        frente = n;
        ultimo = n;
        size++;
        return;
    }
    ultimo->anterior = n;
    ultimo = n;

    size++;
}

bool Colas::isVacia()
{
    return frente;
}

NodoCola* Colas::getFrente()
{
    return frente;
}

void Colas::anular()
{
    while(quitarDeCola());
}

void Colas::imprimir()
{
    ui->listWidget->clear();
    if(size > 0)
    {
        NodoCola* imp = frente;
        for(int i = 0; i < size; i++)
        {
                QString s;
                ui->listWidget->addItem(s.number(imp->valor));
                imp = imp->anterior;
        }
        ui->pushVacia->setVisible(true);
        ui->pushFrente->setVisible(true);
    }
    else
    {
        ui->isVacia->setText("Vacia");
        ui->valorFrente->setText("NULL");
        ui->pushVacia->setVisible(false);
        ui->pushFrente->setVisible(false);
    }
}

void Colas::on_pushPoner_clicked()
{
    int n = ui->spinPoner->value();
    NodoCola* temp = new NodoCola(n);
    ponerEnCola(temp);
    imprimir();
}

void Colas::on_pushQuitar_clicked()
{
    quitarDeCola();
    imprimir();
}

void Colas::on_pushAnular_clicked()
{
    anular();
    imprimir();
}

void Colas::on_pushFrente_clicked()
{
    QString s;
    if(frente){
        ui->valorFrente->clear();
        int t = getFrente()->valor;
        ui->valorFrente->setText(s.number(t));
    }
    else
    {
        QString s = "NULL";
        ui->valorFrente->setText(s);
    }
}

void Colas::on_pushVacia_clicked()
{
    ui->isVacia->clear();
    bool v = isVacia();
    QString s = (v ? "No Vacio" : "Vacio");
    ui->isVacia->setText(s);
}


Colas::~Colas()
{
    delete ui;
}
