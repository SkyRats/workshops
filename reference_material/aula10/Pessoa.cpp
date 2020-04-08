#include "Pessoa.h"

Pessoa::Pessoa(string nome, double valorPorHora, int horasDiarias):
    nome(nome), valorPorHora(valorPorHora), horasDiarias(horasDiarias) {
}

Pessoa::~Pessoa() {
}

string Pessoa::getNome() {
    return nome;
}

double Pessoa::getValorPorHora() {
    return valorPorHora;
}

int Pessoa::getHorasDiarias() {
    return horasDiarias;
}

double Pessoa::getCusto(int dias) {
    return (dias * horasDiarias * valorPorHora);
}

void Pessoa::imprimir() {
    cout << nome << " - R$"
         << valorPorHora << " - "
         << horasDiarias << " hora(s)"
         << endl;
}
