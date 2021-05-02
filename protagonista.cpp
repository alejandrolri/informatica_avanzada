
#include <iostream>
#include <string>
#include "protagonista.hpp"

using namespace std;


Protagonista::Protagonista(){
    vida = 100;
}

Protagonista::~Protagonista(){}

void Protagonista::salud(int dano){
    vida = vida - dano;
}

//Guerrero
Guerrero::Guerrero(){
}
void Guerrero::equiparArma(){

}
void Guerrero::equiparArmadura(){

}

//Mago
void Mago::elegirGremio(){

}
void Mago::Magia(){

}
//Arquero
void Arquero::equiparArco(){

}
void Arquero::seleccionarRaza(){

}
