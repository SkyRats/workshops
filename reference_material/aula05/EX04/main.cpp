#include <iostream>
#include "Sensor.h"
#include "Residencia.h"

using namespace std;

int main(int argc, char **argv) {
  int *p = new int;
  Residencia *r = new Residencia (); // Construtor sem parametros
  Sensor *s = new Sensor(5, r); // Construtor com parametros

  delete p;
  delete r;
  delete s;

  // Arranjos
  int maximo;
  cin >> maximo;

  int *inteiros = new int[maximo];          // Vetor para max. inteiros
  Sensor **sensores = new Sensor*[maximo]; // Vetor para max. sensores

  for (int i = 0; i < maximo; i++) {
    inteiros[i] = i + 1;
    sensores[i] = new Sensor(i, NULL);
  }

  for (int i = 0; i < maximo; i++) {
    cout << "Sensor " << sensores[i]->getNumero() << endl;
    delete sensores[i];
  }

  delete[] inteiros;
  delete[] sensores;

  return 0;
}
