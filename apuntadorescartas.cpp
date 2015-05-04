#include "apuntadorescartas.h"
#include "ui_apuntadorescartas.h"
using namespace std;

ApuntadoresCartas::ApuntadoresCartas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ApuntadoresCartas)
{
    ui->setupUi(this);
    size = 0;
    inicio = NULL;
    final = NULL;
}

ApuntadoresCartas::~ApuntadoresCartas()
{
    delete ui;
}

Cartas* ApuntadoresCartas::getFinal()
{
    return final;
}

void ApuntadoresCartas::agregar(int num)
{
    size++;
    if(!inicio)
    {
        inicio = new Cartas(num);
        final = inicio;
        return;
    }

    final->sig = new Cartas(num);
    final = final->sig;
}

Cartas* ApuntadoresCartas::getPos(int pos)
{
    if(pos>=0 && pos<size)
    {
        if(pos==size-1)
        {
            return final;
        }
        else
        {
            Cartas* temp = inicio;
            for(int i = 1; i <= pos; i++)
            {
                temp = temp->sig;
            }
            return temp;
        }
    }

    return NULL;
}

void ApuntadoresCartas::insertar(int pos, int num)
{
    if(pos>=0 && pos < size){
        if(pos == 0)
        {
            Cartas* temp = new Cartas(num);
            temp->sig = inicio;
            inicio = temp;
            size++;
        }
        else if(pos == size-1)
        {
            agregar(num);
        }
        else
        {
            Cartas* temp = getPos(pos-1);
            Cartas* tem = new Cartas(num);
            tem->sig = temp->sig;
            temp->sig = tem;
            size++;
        }
    }
}

void ApuntadoresCartas::eliminar(int pos)
{
    pos -= 1;
    if(pos>=0 && pos<size-1)
    {
        Cartas* temp = getPos(pos);
        Cartas* tem = temp->sig;
        temp->sig = tem->sig;
        delete tem;
        size--;
    }
    else if(pos>0)
    {
       Cartas* temp = inicio;
       inicio = inicio->sig;
       delete temp;
       size--;
    }
    else if(pos==size-2)
    {
        Cartas* temp = getPos(pos);
        temp->sig = NULL;
        delete final;
        final = temp;
        size--;
    }
}

Cartas* ApuntadoresCartas::buscar(int num)
{
    Cartas* temp = inicio;
    for(int i = 0; i < size; i++)
    {
        if(num == temp->numero)
        {
            return temp;
        }
        temp=temp->sig;
    }
    return NULL;
}

void ApuntadoresCartas::imprimirPantalla()
{
    ui->listWidget->clear();
    QString a;
    Cartas* temp = inicio;
    for(int i = 0; i < size; i++){
        a = a.number(temp->numero);

        if(i < size-1){
            a.append(" -> \n");
        }
        else
        {
            a.append(" -> NULL");
        }

        ui->listWidget->addItem(a);

        if(temp->sig != NULL)
        {
            temp = temp->sig;
        }
    }
}

void ApuntadoresCartas::on_pushAgregar_clicked()
{
    int x = ui->spinAgregar->value();
    agregar(x);
    imprimirPantalla();
}

void ApuntadoresCartas::on_pushInsertar_clicked()
{
     int pos = ui->spinInsertarPos->value();
     int num = ui->spinInsertarNum->value();

     insertar(pos, num);
     imprimirPantalla();
}

void ApuntadoresCartas::on_pushEliminar_clicked()
{
    int x = ui->spinEliminar->value();
    eliminar(x);
    imprimirPantalla();
}

void ApuntadoresCartas::on_pushBuscar_clicked()
{
    ui->resultBuscar->clear();
    int x = ui->spinBuscar->value();
    Cartas* a = buscar(x);
    QString t = " ";

    if(a != NULL)
    {
    int y = a->numero;
    t.append(t.number(y));

    if(a == final)
    {
        t.append(" - Ultimo");
    }
    else if(a->sig != NULL)
    {
        cout<<a->sig->numero<<endl;
        t.append(" -> ");
        y = a->sig->numero;
        t.append(t.number(y));
    }

    }
    else
        t.append(" - No Existe");

    ui->resultBuscar->setText(t);
}


