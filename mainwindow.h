#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int i=0;

private slots:
    void on_Avanzar_clicked();

private:
    void mostrarImagen(int);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
