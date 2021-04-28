#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>


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
    //Imagen del personaje
    protagonista(d.personaje);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mostrarImagen(int i)
{
    switch (i) {
    case 1 :
        ui->Imagen->setPixmap(QPixmap(":/new/prefix1/cueva.png"));
        break;
    case 2 :
        ui->Imagen->setPixmap(QPixmap(":/new/prefix1/orco.jpg"));
        break;
    case 3 :
        ui->Imagen->setPixmap(QPixmap(":/new/prefix1/puertas.png"));
        break;
    case 4 :
        ui->Imagen->setPixmap(QPixmap(":/new/prefix1/mago.jpg"));
        break;
    case 5 :
        ui->Imagen->setPixmap(QPixmap(":/new/prefix1/tesoro.jpg"));
        break;
    }
}

void MainWindow::protagonista(std::string personaje)
{
 if(personaje=="guerrero")
     ui->Personaje->setPixmap(QPixmap(":/new/prefix1/caballero.png"));
 else if (personaje=="mago")
     ui->Personaje->setPixmap(QPixmap(":/new/prefix1/brujo.jpg"));
 else if (personaje=="arquero")
     ui->Personaje->setPixmap(QPixmap(":/new/prefix1/arquero.png"));
}

void MainWindow::botones_puertas()
{
    ui->Avanzar->setText("Puerta 1");
    ui->Atacar->setText("Puerta 2");
    ui->Huir->setText("Puerta 3");
}

void MainWindow::botones()
{
    ui->Avanzar->setText("Avanzar");
    ui->Atacar->setText("Atacar");
    ui->Huir->setText("Huir");
}

void MainWindow::historia()
{
    if(avanzar==1)
        mostrarImagen(1);
    if(avanzar==2)
    {
        mostrarImagen(2);
        ui->Avanzar->setEnabled(false);
        ui->Atacar->setEnabled(true);
        ui->Huir->setEnabled(true);
    }
    //Orco
    if(atacar==1 && huir==0)
    {
        mostrarImagen(3);
        ui->Avanzar->setEnabled(true);
        botones_puertas();
        pocima = true;
    }
    if(huir==1 && atacar==0)
    {
        mostrarImagen(3);
        ui->Avanzar->setEnabled(true);
        botones_puertas();
        pocima = false;
    }
    //Puertas
    //Puerta 1
    if(avanzar==3)
    {
        mostrarImagen(4);
        botones();
    }
    //Puerta 2
    if(atacar==2 || (atacar+huir==2 && pocima))
    {
        mostrarImagen(5);
        botones();
    }
    //Puerta 3
    if(huir==2 || (atacar+huir==2 && pocima))
    {
        mostrarImagen(1);
        botones();
    }
}


void MainWindow::on_Atacar_clicked()
{
    atacar++;
    historia();
}

void MainWindow::on_Huir_clicked()
{
    huir++;
    historia();
}

void MainWindow::on_Avanzar_clicked()
{
    avanzar++;
    historia();
}
