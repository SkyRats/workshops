#include <iostream>
#include "Sensor.h"
#include "Residencia.h"

using namespace std;

int main(int argc, char **argv) {
  Residencia *r = new Residencia (); // Construtor sem parametros

  Sensor *s1 = new Sensor(1, r); // Construtor com parametros
  Sensor *s2 = new Sensor(2, r);

  cout << "Sensor " << s1->getNumero() << " criado" << endl;
  cout << "Sensor " << s2->getNumero() << " criado" << endl;

  return 0;
}
