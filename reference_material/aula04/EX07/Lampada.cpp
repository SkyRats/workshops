#include "Lampada.h"
#include <iostream>

using namespace std;

void Lampada::ligar() {
	acesa = true;
}
void Lampada::desligar() {
	acesa = false;
}
void Lampada::ligarSeNoite(bool ehNoite) {
	if (ehNoite) ligar();
	else desligar();
}

void Lampada::imprimir() {
  cout << this->acesa << endl;
}
