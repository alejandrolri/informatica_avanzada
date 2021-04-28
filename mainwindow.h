#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Avanzar_clicked();
    void on_Atacar_clicked();
    void on_Huir_clicked();

private:
    bool pocima;
    int avanzar = 0;
    int huir = 0;
    int atacar = 0;
    void mostrarImagen(int);
    void protagonista(std::string);
    void botones_puertas();
    void botones();
    void historia();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
