#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/new/prefix1/escena.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        this->setPalette(palette);
        ui->Imagen->setPixmap(QPixmap(":/new/prefix1/orco.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Avanzar_clicked()
{
   ui->Imagen->setPixmap(QPixmap(":/new/prefix1/mago.jpg"));
}
