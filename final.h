#ifndef FINAL_H
#define FINAL_H

#include <QDialog>

namespace Ui {
class Final;
}

class Final : public QDialog
{
    Q_OBJECT

public:
    explicit Final(QWidget *parent = nullptr);
    ~Final();
    void texto();
private:
    Ui::Final *ui;
};

#endif // FINAL_H
