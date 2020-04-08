#ifndef SENSOR_H
#define SENSOR_H

#include "Residencia.h"

class Sensor {
public:
  Sensor(int numero, Residencia *residencia); // Construtor
  ~Sensor();
  void detectarAcao() const;

  int getNumero();
  void setNumero(int numero);
private:
  int numero;
  Residencia *residencia;
};

#endif // SENSOR_H
