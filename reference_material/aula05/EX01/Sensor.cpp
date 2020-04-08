#include <iostream>
#include "Sensor.h"

using namespace std;

Sensor::Sensor(int numero, Residencia *residencia) : numero(numero), residencia(residencia) {
  // Pode fazer outras inicializacoes
}

int Sensor::getNumero() {
  return numero;
}

void Sensor::detectarAcao() {
  // Nao faz nada
}
