#include "ordenararreglo.h"
#include "ui_ordenararreglo.h"
#include <QString>


OrdenarArreglo::OrdenarArreglo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrdenarArreglo)
{
    array_size = 10;
    cont = 0;
    borrados = 0;
    ui->setupUi(this);
}

OrdenarArreglo::~OrdenarArreglo()
{
    delete ui;
}

void OrdenarArreglo::deleteIndex(int pos, int array[])
{
    cout<<"Pos: "<<pos<<" #: "<<array[pos]<<endl;
        for(int i = pos; i < (array_size); i++)
        {
            /**
              Si borro este if y lo dejo que agarre el espacio
              basura puede funcionar mas de una ves, sino solo
              solo funciona una ves, la segundo termina de
              llenar el arreglo con -1
              */
           if(i != array_size-1)
            {
            array[i] = array[i+1];
            array[i+1] = -1;
            }
        }

    llenarArray("Ordenando");
}

int cont = 0;
void OrdenarArreglo::on_agregarArray_clicked()
{
    if(cont <= 9){
        array[cont] = ui->spinOrdenar->value();
        cout<<cont<<") Agegardo: "<<ui->spinOrdenar->value()<<endl;
        QString s;
        ui->listWidget_2->addItem(s.number(ui->spinOrdenar->value()));
        cont++;
    }
}

void OrdenarArreglo::on_pushOrdenar_clicked()
{
    ui->listWidget->clear();

    QString s;
    borrados = 0;
    llenarArray("Principio");
    cout<<"Ordenando..."<<endl;
    for(int i = 0; i < (array_size-borrados); i++)
    {
        for(int j = 0; j < (array_size-borrados); j++ )
        {
            if(array[i]==array[j] && array[j] != -1 && array[i] != -1 )
            {
                cont++;
            }

            if(cont > 1)
            {
                deleteIndex(j, array);
                i -= 1;
                borrados += 1;
            }
        }
            cont  = 0;
    }

    int k = 0;
    cout<<" Size: "<<(array_size-borrados)<<endl;
    int ordenado[array_size-borrados];
    llenarArray("Final");

    while(k < array_size-borrados)
    {
        ordenado[k] = array[k];
        cout<<(k+1)<<"- "<<ordenado[k]<<" !K: "<<k<<endl;
        QString i;
        ui->listWidget->addItem(i.number(ordenado[k]));
        k++;
    }

    k = 0;
}

void OrdenarArreglo::llenarArray(string a)
{
    for(int i = 0; i < array_size; i++)
    {
        cout<<i<<") "<<array[i]<<" -> "<<a<<endl;
    }

}
