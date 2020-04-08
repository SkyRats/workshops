#include "Pessoa.h"
#include <iostream>

using namespace std;

string Pessoa::getNome() {
    return this->nome;
}

int Pessoa::getHorasDiarias() {
    return this->horasDiarias;
}

void Pessoa::imprimir() {
    cout << this->nome << ": " << this->horasDiarias << " hora(s) por dia" << endl;
}
Pessoa::Pessoa(string nome, int horasDiarias) : nome (nome), horasDiarias (horasDiarias)
{

}
Pessoa::~Pessoa()
{
    cout << "Pessoa " << this->nome << " destruida" << endl;
}
