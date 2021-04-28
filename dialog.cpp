#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //Fondo
    QPixmap bkgnd(":/new/prefix1/fondo_dialogo.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        this->setPalette(palette);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_Guerrero_clicked()
{
    personaje = "guerrero";
}

void Dialog::on_Mago_clicked()
{
    personaje = "mago";
}

void Dialog::on_Arquero_clicked()
{
    personaje = "arquero";
}
