#include "pilas.h"
#include "ui_pilas.h"

Pilas::Pilas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pilas)
{
    ui->setupUi(this);
    tope = NULL;
    size = 0;

    ui->pushVacia->setVisible(false);
    ui->pushTope->setVisible(false);
    ui->isVacia->setText("Vacia");
    ui->valorTope->setText("NULL");
}

NodoPila *Pilas::getTope()
{
    return tope;
}

bool Pilas::sacar()
{
    if(tope && size > 0)
    {
        NodoPila* t = tope;
        tope = tope->anterior;
        delete t;
        size--;
        return true;
    }
    return false;
}

void Pilas::meter(NodoPila* nodo)
{
    if(tope)
    {
        nodo->anterior = tope;
    }
        tope = nodo;
        size++;
}

bool Pilas::isVacia()
{
    return tope;
}

void Pilas::anular()
{
    while(sacar());
}

void Pilas::imprimir()
{
    ui->listWidget->clear();
    if(size > 0)
        {
        NodoPila* imp = tope;
        for(int i = 0; i < size; i++)
        {
                QString s;
                ui->listWidget->addItem(s.number(imp->valor));
                imp = imp->anterior;
        }
            ui->pushVacia->setVisible(true);
            ui->pushTope->setVisible(true);
    }
    else
    {
        ui->isVacia->setText("Vacia");
        ui->valorTope->setText("NULL");
        ui->pushVacia->setVisible(false);
        ui->pushTope->setVisible(false);
    }
}

void Pilas::on_pushMeter_clicked()
{
    int n = ui->spinMeter->value();
    NodoPila* temp = new NodoPila(n);
    meter(temp);
    imprimir();
}

void Pilas::on_pushSacar_clicked()
{
    sacar();
    imprimir();
}

void Pilas::on_pushAnular_clicked()
{
    anular();
    imprimir();
}

void Pilas::on_pushTope_clicked()
{
    QString s;
    if(tope){
        ui->valorTope->clear();
        int t = getTope()->valor;
        ui->valorTope->setText(s.number(t));
    }
    else
    {
        QString s = "NULL";
        ui->valorTope->setText(s);
    }
}

void Pilas::on_pushVacia_clicked()
{
    ui->isVacia->clear();
    bool v = isVacia();
    QString s = (v ? "No Vacio" : "Vacio");
    ui->isVacia->setText(s);
}

Pilas::~Pilas()
{
    delete ui;
}
