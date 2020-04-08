#include <iostream>
#include "Sensor.h"

using namespace std;

Sensor::Sensor(int numero, Residencia *residencia) : numero(numero), residencia(residencia) {
}

Sensor::~Sensor() {
  cout << "Destruido" << endl;
}


int Sensor::getNumero() {
  return numero;
}

void Sensor::setNumero(int numero) {
  this->numero = numero;
}

void Sensor::detectarAcao() const {
  //this->numero = 0;
}
