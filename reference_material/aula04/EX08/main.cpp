#include <iostream>
#include "Relogio.h"

using namespace std;

int main() {
	Relogio *relogios[2];
	relogios[0] = new Relogio;
	relogios[0]->inicializar(10, 20);
	relogios[1] = new Relogio;
	relogios[1]->inicializar(18, 30);

	for (int i = 0; i < 2; i++)
		relogios[i]->imprimir();

	return 0;
}
