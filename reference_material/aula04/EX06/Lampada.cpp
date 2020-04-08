#include "Lampada.h"
#include <iostream>

using namespace std;

void Lampada::ligar() {
	acesa = true;
}
void Lampada::desligar() {
	acesa = false;
}
void Lampada::ligarSeNoite(Relogio *horaAtual) {
	int hora = horaAtual->getHora();
	if (hora >= 18) ligar();
	else desligar();
}

void Lampada::imprimir() {
  cout << this->acesa << endl;
}
