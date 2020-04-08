#include "Atividade.h"


Atividade::Atividade(string nome, int horasNecessarias, int maximoPessoas) : nome(nome),
                     horasNecessarias(horasNecessarias), maximoPessoas(maximoPessoas) {

    this->pessoas = new Pessoa*[maximoPessoas];
    this->quantidade = 0;
}

Atividade::~Atividade() {
    for (int i = 0; i < quantidade; i++) {
        delete pessoas[i];
    }
    delete[] pessoas;
}

int Atividade::getHorasNecessarias() {
    return horasNecessarias;
}

bool Atividade::adicionar(Pessoa* p) {
    if (quantidade < maximoPessoas) {
        pessoas[quantidade++] = p;
        return true;
    }
    return false;
}

int Atividade::getDuracao() {
    double horas = 0;

    if (quantidade == 0)
        return -1;

    for (int i = 0; i < quantidade; i++)
        horas += pessoas[i]->getHorasDiarias();

    return ceil(horasNecessarias/horas);
}

int Atividade::getQuantidade() {
    return quantidade;
}

Pessoa** Atividade::getPessoas() {
    return pessoas;
}

void Atividade::imprimir() {
    cout << nome << " - " << getDuracao() << " dias estimados" << endl;
    for (int i = 0; i < quantidade; i++)
        pessoas[i]->imprimir();
    cout << endl;
}

