#include "final.h"
#include "ui_final.h"

Final::Final(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Final)
{
    ui->setupUi(this);
    //Fondo
    QPixmap bkgnd(":/new/prefix1/fondo_dialogo.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        this->setPalette(palette);
}

Final::~Final()
{
    delete ui;
}

void Final::texto(){
    ui->textEdit->setText("NO HAS PODIDO SALVAR A LA CIUDAD");
}
