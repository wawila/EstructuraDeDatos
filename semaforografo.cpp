#include "semaforografo.h"
#include "ui_semaforografo.h"

SemaforoGrafo::SemaforoGrafo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SemaforoGrafo)
{
    ui->setupUi(this);
}

SemaforoGrafo::~SemaforoGrafo()
{
    delete ui;
}
