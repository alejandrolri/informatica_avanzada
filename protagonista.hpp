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
        void vida(int); 
};
//Clase derivada de Protagonista --> Guerrero
class Guerrero:public Protagonista{
        int arma;
    public:
        Guerrero();
        ~Guerrero();
        void AumentarFuerza();
};
//Clase derivada de Protagonista --> Mago
class Brujo:public Protagonista{
        int tipoMagia;
    public:
        Brujo();
        ~Brujo();
        void Magia();
};
//Clase derivada de Protagonista --> Arquero
class Arquero:public Protagonista{
        int arco;
    public:
        Arquero();
        ~Arquero();
        void equiparArco();
};
