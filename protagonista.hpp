#ifndef PROTAGONISTA_H
#define PROTAGONISTA_H
#include <iostream>
#include <string>

using namespace std;
//Clase Padre --> Protagonista
class Protagonista{
    public:
        int rol;
        int vida;
        Protagonista();
        ~Protagonista();
        virtual void salud(int);
};

//Clase derivada de Protagonista --> Guerrero
class Guerrero:public Protagonista{
        int arma;
    public:
        Guerrero();
        ~Guerrero();
        void equiparArma();
        void equiparArmadura();
};
//Clase derivada de Protagonista --> Mago
class Mago:public Protagonista{
        int magia;
    public:
        Mago();
        ~Mago();
        void elegirGremio();
        void Magia();
};
//Clase derivada de Protagonista --> Arquero
class Arquero:public Protagonista{
        int arco;
    public:
        Arquero();
        ~Arquero();
        void equiparArco();
        void seleccionarRaza();
};

#endif
