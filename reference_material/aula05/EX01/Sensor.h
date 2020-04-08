#ifndef SENSOR_H
#define SENSOR_H

#include "Residencia.h"

class Sensor {
public:
  Sensor(int numero, Residencia *residencia); // Construtor
  void detectarAcao();

  int getNumero();
private:
  int numero;
  Residencia *residencia;
};

#endif // SENSOR_H
