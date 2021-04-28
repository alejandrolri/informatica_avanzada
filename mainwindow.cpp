#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
#include <QDialog>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Fondo
    QPixmap bkgnd(":/new/prefix1/escena.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        this->setPalette(palette);
    //Imagen inicial
    ui->Imagen->setPixmap(QPixmap(":/new/prefix1/castillo.png"));
    //Diálogo selección
    Dialog d;
    d.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Avanzar_clicked()
{
   i++;
   mostrarImagen(i);
}

void MainWindow::mostrarImagen(int i)
{
    switch (i) {
    case 1 :
        ui->Imagen->setPixmap(QPixmap(":/new/prefix1/cueva.png"));
        ui->lineEdit->setText("Sos otaku");
        break;
    case 2 :
        ui->Imagen->setPixmap(QPixmap(":/new/prefix1/orco.jpg"));
        break;
    case 3 :
        ui->Imagen->setPixmap(QPixmap(":/new/prefix1/mago.jpg"));
        break;
    case 4 :
        ui->Imagen->setPixmap(QPixmap(":/new/prefix1/tesoro.jpg"));
        break;
    }
}
