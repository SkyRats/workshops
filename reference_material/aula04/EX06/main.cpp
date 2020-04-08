#include <iostream>
#include "Lampada.h"
#include "Relogio.h"

using namespace std;

int main() {
	Lampada *sala = new Lampada;
	Relogio *r = new Relogio;
	r->inicializar(10, 30);
	sala->ligarSeNoite(r);
	sala->imprimir();

	r->inicializar(19, 30);
	sala->ligarSeNoite(r);
	sala->imprimir();

	return 0;
}
