#include <iostream>
#include "Sensor.h"
#include "Residencia.h"

using namespace std;

int main(int argc, char **argv) {
  Sensor *s1 = new Sensor(1, NULL);
  Sensor *s2 = new Sensor(2, NULL);

  cout << "Sensor " << s1->getNumero() << " criado" << endl;
  cout << "Sensor " << s2->getNumero() << " criado" << endl;

  return 0;
}
