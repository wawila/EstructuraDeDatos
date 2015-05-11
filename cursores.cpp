#include "cursores.h"
#include "ui_cursores.h"

Cursores::Cursores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cursores)
{
    ui->setupUi(this);
}

/**
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
 */

int Cursores::buscar(int lista, QString valor)
{
    if(inicio[lista])
    {
        int x = inicio[lista];
        while(espacio[x].valor != valor)
        {
            x = espacio[x].sig;

            if(x == -1)
                return -1;
        }

        return x;
    }

    return -1;
}

// que es valorInicio;
void Cursores::crearLista(QString valor)
{
    if(inicio[0])
    {
        int disp = inicio[0];
        //inicio[vacioInicio()] = disp;
        inicio[0] = espacio[disp].sig;
        espacio[disp].sig = -1;
        espacio[disp].valor = valor;
    }
}

void Cursores::agregar(int lista, QString valor)
{
    if(inicio[0])
    {
        int x = inicio[lista];
        while(espacio[x].sig != -1)
            x = espacio[x].sig;

        int y = inicio[0];
        espacio[y].valor = valor;
        inicio[0] = espacio[y].sig;
        espacio[y].sig = -1;
    }
}

// Valor del if;
void Cursores::insertar(int lista, QString valor, int pos)
{
    int x = inicio[0];
    if(pos >= 0)
    {
        if(pos==inicio[lista] && espacio[pos].sig != -1)
        {
            inicio[0] = espacio[x].sig;
            espacio[x].valor = valor;
            espacio[x].sig = inicio[lista];
            inicio[lista] = x;
        }
        else if(espacio[pos].sig == -1)
        {
            agregar(lista, valor);
        }
        else
        {
            inicio[0] = espacio[x].sig;
            espacio[x].valor = valor;
            espacio[x].sig = espacio[pos].sig;
            espacio[pos].sig = x;
        }
    }
}

void Cursores::eliminar(int lista, int pos)
{
    int actual = buscar(lista, espacio[pos].valor);
    if(actual == inicio[lista])
    {
        agregar(0, espacio[actual].valor);
        inicio[lista] = espacio[actual].sig;
        espacio[actual].sig = -1;
    }
}

Cursores::~Cursores()
{
    delete ui;
}
