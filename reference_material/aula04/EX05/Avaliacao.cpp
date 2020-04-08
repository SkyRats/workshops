#include "Avaliacao.h"

void Avaliacao::setNotas (double p1, double p2, double p3) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

double Avaliacao::getMedia() {
	return (p1 + p2 + 2 * p3) / 4;
}
