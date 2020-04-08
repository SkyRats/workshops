#include "Relogio.h"
#include <iostream>

using namespace std;

void Relogio::inicializar (int hora, int minuto) {
	if (hora < 0 || hora > 23) this->hora = 0;
	else this->hora = hora;

	if (minuto < 0 || minuto > 59) this->minuto = 0;
	else this->minuto = minuto;
}

int Relogio::getHora() {
	return hora;
}

int Relogio::getMinuto() {
	return minuto;
}

void Relogio::imprimir() {
	cout << hora << ":" << minuto << endl;
}
