#include "semaforografo.h"
#include "ui_semaforografo.h"

SemaforoGrafo::SemaforoGrafo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SemaforoGrafo)
{
    ui->setupUi(this);

        AB = new Calle("AB");
        AC = new Calle("AC");
        AD = new Calle("AD");
        BA = new Calle("BA");
        BC = new Calle("BC");
        BD = new Calle("BD");
        DA = new Calle("DA");
        DB = new Calle("DB");
        DC = new Calle("DC");
        EA = new Calle("EA");
        EB = new Calle("EB");
        EC = new Calle("EC");
        ED = new Calle("ED");

        /** ---Adyacentes--- **/
        // AB
        AB->adyacentes.push_back(BC);
        AB->adyacentes.push_back(BD);
        AB->adyacentes.push_back(DA);
        AB->adyacentes.push_back(EA);
        // AC
        AC->adyacentes.push_back(BD);
        AC->adyacentes.push_back(DA);
        AC->adyacentes.push_back(DB);
        AC->adyacentes.push_back(EA);
        AC->adyacentes.push_back(EB);
        // AD
        AD->adyacentes.push_back(EA);
        AD->adyacentes.push_back(EB);
        AD->adyacentes.push_back(EC);
        // BC
        BC->adyacentes.push_back(AB);
        BC->adyacentes.push_back(DB);
        BC->adyacentes.push_back(EB);
        // BD
        BD->adyacentes.push_back(AB);
        BD->adyacentes.push_back(AC);
        BD->adyacentes.push_back(DB);
        BD->adyacentes.push_back(DA);
        BD->adyacentes.push_back(EB);
        BD->adyacentes.push_back(EC);
        // DA
        DA->adyacentes.push_back(AB);
        DA->adyacentes.push_back(AC);
        DA->adyacentes.push_back(BD);
        DA->adyacentes.push_back(EB);
        DA->adyacentes.push_back(EC);
        // DB
        DB->adyacentes.push_back(AC);
        DB->adyacentes.push_back(BC);
        DB->adyacentes.push_back(EC);
        // EA
        EA->adyacentes.push_back(AB);
        EA->adyacentes.push_back(AC);
        EA->adyacentes.push_back(AD);
        // EB
        EB->adyacentes.push_back(AC);
        EB->adyacentes.push_back(AD);
        EB->adyacentes.push_back(BC);
        EB->adyacentes.push_back(BD);
        EB->adyacentes.push_back(DA);
        // EC
        EC->adyacentes.push_back(AD);
        EC->adyacentes.push_back(BD);
        EC->adyacentes.push_back(DA);
        EC->adyacentes.push_back(DB);

        calles.push_back(AB);
        calles.push_back(AC);
        calles.push_back(AD);
        calles.push_back(BA);
        calles.push_back(BC);
        calles.push_back(BD);
        calles.push_back(DA);
        calles.push_back(DB);
        calles.push_back(DC);
        calles.push_back(EA);
        calles.push_back(EB);
        calles.push_back(EC);
        calles.push_back(ED);

        label.push_back(ui->AB);
        label.push_back(ui->AC);
        label.push_back(ui->AD);
        label.push_back(ui->BA);
        label.push_back(ui->BC);
        label.push_back(ui->BD);
        label.push_back(ui->DA);
        label.push_back(ui->DB);
        label.push_back(ui->DC);
        label.push_back(ui->EA);
        label.push_back(ui->EB);
        label.push_back(ui->EC);
        label.push_back(ui->ED);

        colores.append("BLANCO");
        colores.append("AZUL");
        colores.append("ROJO");
        colores.append("VERDE");
        colores.append("AMARILLO");


        listo.clear();

}

void SemaforoGrafo::imprimirCalles()
{
    cout<<"AB - "<<AB->color.toStdString()<<endl;
    cout<<"AC - "<<AC->color.toStdString()<<endl;
    cout<<"AD - "<<AD->color.toStdString()<<endl;
    cout<<"BA - "<<BA->color.toStdString()<<endl;
    cout<<"BC - "<<BC->color.toStdString()<<endl;
    cout<<"BD - "<<BD->color.toStdString()<<endl;
    cout<<"DA - "<<DA->color.toStdString()<<endl;
    cout<<"DB - "<<DB->color.toStdString()<<endl;
    cout<<"DC - "<<DC->color.toStdString()<<endl;
    cout<<"EA - "<<EA->color.toStdString()<<endl;
    cout<<"EB - "<<EB->color.toStdString()<<endl;
    cout<<"EC - "<<EC->color.toStdString()<<endl;
    cout<<"ED - "<<ED->color.toStdString()<<endl;
}

bool SemaforoGrafo::chequearBlancos()
{
    for(int i = 0; i < calles.size(); i++)
    {
        if(calles[i]->color == "BLANCO")
        {
            return true;
        }
    }
    return false;
}

bool SemaforoGrafo::grupoPintado(Calle *calle)
{
    for(int i = 0; i < calle->getAdyacente().size(); i++)
    {
        for(int j = 0; j < listo.size(); j++)
        {
            if(calle->getAdyacente()[i]->getNombre() == listo[j]->getNombre())
            {
                return true;
            }
        }
    }
    return false;
}

void SemaforoGrafo::pintar()
{
    for(int c = 1; c < colores.size(); c++)
    {
        for(int i = 0; i < calles.size(); i++)
        {
            if(calles[i]->getColor() == "BLANCO")
            {
                if(grupoPintado(calles[i]) == false)
                {
                   calles[i]->cambiarColor(colores[c]);
                   listo.append(calles[i]);
                }
            }
        }

        cout<<"---Color---"<<colores[c].toStdString()<<endl;
    }

}

void SemaforoGrafo::on_pushPintar_clicked()
{
   pintar();
   imprimirCalles();
}

SemaforoGrafo::~SemaforoGrafo()
{
    delete ui;
}
