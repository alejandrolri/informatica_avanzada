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
    ui->textEdit->setText("Tu aventura comienza en la ciudad de Morioh, donde el gremio de aventureros te ha llamado para acabar con una maldición que asola la ciudad desde hace siglos");
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
    if(avanzar==1){
        mostrarImagen(1);
        ui->textEdit->setText("Tras equiparte concienzudamente, decides emprender camino hacia la cueva. Desprende un aura de peligro que te hiela la sangre\n");
    }
    if(avanzar==2)
    {
        mostrarImagen(2);
        ui->Avanzar->setEnabled(false);
        ui->Atacar->setEnabled(true);
        ui->Huir->setEnabled(true);
        ui->textEdit->setText("De repente escuchas un ruido proveniente del interior, tras avanzar unos metros descubres un orco que te corta el paso. Parece imponente. No puedes avanzar, solo tienes la opción de luchar o huir");
    }
    //Orco
    if(atacar==1 && huir==0)
    {
        mostrarImagen(2);
        ui->Avanzar->setEnabled(true);
        ui->Atacar->setEnabled(false);
        ui->Huir->setEnabled(false);
        ui->textEdit->setText("Consigues matar al orco en una dura pelea que te deja al borde de la muerte. Al rebuscar entre sus pertenencias descubres dos pociones y una llave. Una de ellas te permite restaurar tu salud por completo. Observas una marca en su cabeza ('III').¿Qué podra significar?");
    }
    if(avanzar==3 && atacar==1){
        mostrarImagen(2);
        ui->Avanzar->setEnabled(false);
        ui->Atacar->setEnabled(true);
        ui->Huir->setEnabled(false);
        ui->textEdit->setText("Justo después te encuentras con un slime gigante bastante inofensivo. Decides atacar. Dichosos bichos, están por todo el reino");
    }
    if(atacar==2){
        mostrarImagen(3);
        ui->Avanzar->setEnabled(true);
        ui->Atacar->setEnabled(true);
        ui->Huir->setEnabled(true);
        ui->textEdit->setText("Descubres que tanto el camino del ogro como el del pasaje cercano conducen a la entrada de una mazmorra con 3 puertas. ¿Qué puerta escoges?");
        botones_puertas();
    }

    if(huir==1 && atacar==0)
    {
        mostrarImagen(3);
        ui->Avanzar->setEnabled(true);
        ui->textEdit->setText("Decides no enfrentarte al orco y huir por un pasaje cercano que te lleva hasta un cofre que contiene una llave. Descubres que tanto el camino del ogro como el del pasaje cercano conducen a la entrada de una mazmorra con 3 puertas. ¿Qué puerta escoges?");
        botones_puertas();
    }
    //Puertas
    //Puerta 1
    if(avanzar==4||(avanzar==3 && huir==1))
    {
        mostrarImagen(4);
        botones();
        ui->textEdit->setText("Escoges la puerta número 1 y te encuentras con un mago oscuro con un gran poder. Sospechas que puede ser el causante de la maldición en la ciudad. Solo tienes la opción de atacar para poder salir de aquí con vida");
        ui->Avanzar->setEnabled(false);
        ui->Atacar->setEnabled(true);
        ui->Huir->setEnabled(false);
    }
    if((avanzar==4 && atacar==3)||(avanzar==3 && huir==1 && atacar==1 )){
        mostrarImagen(5);
        ui->textEdit->setText("Consigues derrotarlo y saqueas todo lo que encuentras para hacer constar en el gremio de tu heroica hazaña");
        ui->Avanzar->setEnabled(true);
        ui->Atacar->setEnabled(false);
        ui->Huir->setEnabled(false);
    }
    if((avanzar==5)||(avanzar==4 && huir==1 && atacar==1 ))
    {
        ui->Imagen->setPixmap(QPixmap(":/new/prefix1/castillo.png"));
        ui->textEdit->setText("Decides volver a la ciudad y descubres que las malas cosechas, la enfermedad y las tinieblas siguen presentes. Has fallado en tu misión y decides darte por vencido. FINAL 1");
        ui->Avanzar->setEnabled(false);
        ui->Atacar->setEnabled(false);
        ui->Huir->setEnabled(false);
    }

    //Puerta 2
    if((avanzar==3 && atacar==3)||(avanzar==2 && atacar==1 && huir==1))
    {
        mostrarImagen(5);
        ui->textEdit->setText("Escoges la puerta número 2 y te encuentras con Lilith, descubres que el hedor que desprende es el mismo que el de la ciudad y que su poder puede ser la causante de la maldición. Solo tienes la opción de atacar para poder salir de aquí con vida");
        botones();
        ui->Avanzar->setEnabled(false);
        ui->Atacar->setEnabled(true);
        ui->Huir->setEnabled(false);
    }
    if((avanzar==3 && atacar==4)||(avanzar==2 && atacar==2 && huir==1))
    {
        mostrarImagen(5);
        ui->textEdit->setText("Con tu poder actual te ves incapaz de salir con vida y mueres tras una ardua batalla. FINAL 2");
        ui->Avanzar->setEnabled(false);
        ui->Atacar->setEnabled(false);
        ui->Huir->setEnabled(false);
    }

    //Puerta 3
    if(huir==2||(avanzar==3 && atacar==2 && huir==1))
    {
        mostrarImagen(2);
        ui->textEdit->setText("Eliges la puerta 3 debido a que recuerdas la marca en la cabeza del ogro e intuyes que puede ser uno de los secuaces que guarde los tesoros de Lilith. Encuentras un arma imbuida en un poder increible y decides remplazarla por la que llevas");
        botones();
        ui->Avanzar->setEnabled(true);
        ui->Atacar->setEnabled(false);
        ui->Huir->setEnabled(false);
    }
    if((huir==2 && avanzar==3)||(avanzar==4 && atacar==2 && huir==1))
    {
        mostrarImagen(5);
        ui->textEdit->setText("Tras unos cuantos metros encuentras a Lilith, descubres que el hedor que desprende es el mismo que el de la ciudad y que su poder puede ser el causante de la maldición. Solo te queda luchar para acabar con todo esto");
        ui->Avanzar->setEnabled(false);
        ui->Atacar->setEnabled(true);
        ui->Huir->setEnabled(false);
    }
    if(huir==2 && avanzar==3 && atacar==1)
    {
        mostrarImagen(5);
        ui->textEdit->setText("Te sientes muy poderoso con tu nuevo arma y peleas a muerte, hasta que en un punto de la batalla Lilith desata todo su poder y te acorrala hasta matarte. FINAL 3");
        ui->Avanzar->setEnabled(false);
        ui->Atacar->setEnabled(false);
        ui->Huir->setEnabled(false);
    }
    if(avanzar==4 && atacar==3 && huir==1){
        mostrarImagen(5);
        ui->textEdit->setText("Te sientes muy poderoso con tu nuevo arma y peleas a muerte, hasta que en un punto de la batalla Lilith está a punto de matarte. De repente una luz ciega a Lilith y eso consigue salvarte.");
        ui->Avanzar->setEnabled(true);
        ui->Atacar->setEnabled(false);
        ui->Huir->setEnabled(false);
    }
    if(avanzar==5 && atacar==3 && huir==1){
        mostrarImagen(5);
        ui->textEdit->setText("Una de las pociones que te quedaba tras derrotar al orco se ha iluminado. Decides tomarla y consigues curarte y aumentar tu poder. Esto te permite acabar con Lilith y con la maldición de la ciudad.");
        ui->Avanzar->setEnabled(true);
        ui->Atacar->setEnabled(false);
        ui->Huir->setEnabled(false);
    }
    if(avanzar==6 && atacar==3 && huir==1){
        ui->Imagen->setPixmap(QPixmap(":/new/prefix1/castillo.png"));
        ui->textEdit->setText("Regresas al gremio de aventureros y te reciben como un héroe, has acabado con la maldición de la ciudad que asolaba sus cosechas, traía enfermedad y penurias. La niebla y el aspecto tenebroso de la ciudad ha desaparecido. FINAL VERDADERO");
        ui->Avanzar->setEnabled(false);
        ui->Atacar->setEnabled(false);
        ui->Huir->setEnabled(false);
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
