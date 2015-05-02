#ifndef SEMAFOROGRAFO_H
#define SEMAFOROGRAFO_H

#include <QDialog>

namespace Ui {
class SemaforoGrafo;
}

class SemaforoGrafo : public QDialog
{
    Q_OBJECT

public:
    explicit SemaforoGrafo(QWidget *parent = 0);
    ~SemaforoGrafo();

private:
    Ui::SemaforoGrafo *ui;
};

#endif // SEMAFOROGRAFO_H
