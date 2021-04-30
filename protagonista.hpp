#include <iostream>
#include <string>

using namespace std;
//Clase Padre --> Protagonista
class Protagonista{
        int rol;
        string nombre;
        int vida;
    public:
        Protagonista();
        ~Protagonista();
        void elegirNombre(string);
        void elegirRol(int);
        void vida(int); //Dependiendo de la vida, el juego sera mas dificil
        virtual void atacar(); 
        virtual void avanzar();
        virtual void huir();
        void informacionGeneral(); //Se mostraran las caracteristicas
};
//Clase derivada de Protagonista --> Guerrero
class Guerrero:public Protagonista{
        int arma;
        int armadura;
    public:
        Guerrero();
        ~Guerrero();
        void equiparArma();
        void equiparArmadura();
};
//Clase derivada de Protagonista --> Mago
class Mago:public Protagonista{
        int gremio;
        int tipoMagia;
    public:
        Mago();
        ~Mago();
        void elegirGremio();
        void Magia();
};
//Clase derivada de Protagonista --> Arquero
class Arquero:public Protagonista{
        int arco;
        int raza;
    public:
        Arquero();
        ~Arquero();
        void equiparArco();
        void seleccionarRaza();
};
