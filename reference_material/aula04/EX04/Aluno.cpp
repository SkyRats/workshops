#include "Aluno.h"

void Aluno::setNome(string nome) {
	this->nome = nome;
}

string Aluno::getNome() {
	return nome;
}

void Aluno::setNotas (double p1, double p2, double p3) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

double Aluno::getMedia() {
	return (p1 + p2 + 2 * p3) / 4;
}
