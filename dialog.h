#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <string>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    std::string personaje;

private slots:
    void on_Guerrero_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
