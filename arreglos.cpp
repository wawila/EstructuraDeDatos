#include "arreglos.h"
#include "ui_arreglos.h"


void Arreglos::imprimirPantalla()
{
    ui->listWidget->clear();
    QString a;
    for(int i = 0; i < agregados; i++){
        a = a.number(arreglo[i]);

        if(i < size-1){
            a.append(" -> \n");
        }

        ui->listWidget->addItem(a);
    }
}


Arreglos::Arreglos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arreglos)
{
    ui->setupUi(this);
    size = 15;
    agregados = 0;
    actual = 0;
    imprimirPantalla();
}

bool Arreglos::insert(int pos, int num)
{
    if(actual < size && pos < actual)
    {
        for(int x = actual-1; x >= pos; x--)
        {
            arreglo[x+1] = arreglo[x];
        }
        arreglo[pos] = num;
        actual++;
        agregados += 1;
        return true;
    }
    return false;

}

int Arreglos::search(int num)
{
    for(int i = 0; i < actual; i++)
    {
        if(arreglo[i] == num)
            return i;
    }
    return -1;
}

void Arreglos::clear()
{
    for(int i = 0; i < actual; i++)
    {
        arreglo[i] = 0;
    }
    actual = 0;
}

bool Arreglos::append(int num)
{
    if(actual < size)
    {
        arreglo[actual++] = num;
        agregados += 1;
        return true;
    }
    return false;

}

bool Arreglos::eliminar(int pos)
{
    if(pos < actual)
    {
        for(int i = pos; i < actual; i++)
        {
            arreglo[i] = arreglo[i+1];

        }
        arreglo[--actual] = 0;
        agregados -= 1;
        return true;
    }
    return false;
}

void Arreglos::on_pushAgregar_clicked()
{
    int x = ui->spinAgregar->value();
    append(x);
    imprimirPantalla();
}

void Arreglos::on_pushInsertar_clicked()
{
     int pos = ui->spinInsertarPos->value();
     int num = ui->spinInsertarNum->value();

     insert(pos, num);
     imprimirPantalla();
}

void Arreglos::on_pushEliminar_clicked()
{
    int x = ui->spinEliminar->value();
    eliminar(x);
    imprimirPantalla();
}

void Arreglos::on_pushBuscar_clicked()
{
    QString a;
    a = "Numero: ";
    a.append(a.number(ui->spinBuscar->value()));
    a.append(" - Posicion: ");
    int p = search(ui->spinBuscar->value());
    if(p >= 0)
        a.append(a.number(p));
    else
        a.append(" No Existe");
    ui->resultBuscar->setText(a);
}

void Arreglos::on_pushClear_clicked()
{
    ui->listWidget->clear();
    clear();
}


Arreglos::~Arreglos()
{
    delete ui;
}
