#include "Pessoa.h"

Pessoa::Pessoa(string nome, int horasDiarias):
  nome(nome), horasDiarias(horasDiarias) {
}

Pessoa::~Pessoa() {
}


int Pessoa::getHorasDiarias() {
  return horasDiarias;
}

void Pessoa::imprimir() {
  cout << nome << ": " << horasDiarias << " hora(s) por dia" << endl;
}
