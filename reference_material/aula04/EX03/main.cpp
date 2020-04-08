#include "Relogio.h"

int main() {
	Relogio *r = new Relogio;
	r->inicializar (10, 5);
	r->imprimir();
	return 0;
}
