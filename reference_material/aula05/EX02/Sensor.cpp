#include <iostream>
#include "Sensor.h"

using namespace std;

Sensor::Sensor(int numero, Residencia *residencia) {
  this->numero = numero;
  this->residencia = residencia;
}

int Sensor::getNumero() {
  return numero;
}

void Sensor::detectarAcao() {
  // Nao faz nada
}
