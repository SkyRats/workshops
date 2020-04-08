#include "Projeto.h"
#include <stdexcept>

Projeto::Projeto(string nome, int maximoValor) : nome(nome), maximoValor(maximoValor) {
    this->quantidadeAtividades = 0;
    this->quantidadePessoas = 0;
    atividades = new vector<Atividade*>();
    pessoas = new Pessoa*[maximoValor];
}

Projeto::~Projeto() {

    delete atividades;
    delete[] pessoas;
}

int Projeto::getDuracao() {
    int duracao = 0;
    for (int i = 0; i < quantidadeAtividades; i++) {
        duracao += atividades->at(i)->getDuracao();
    }
    return duracao;
}

vector<Atividade*>* Projeto::getAtividades()
{
    return atividades;
}

void Projeto::adicionar(Atividade* a) {
    // Atividade ja previamente adicionada
    for (int i = 0; i < atividades->size(); i++) {
        if (atividades->at(i) == a)
            throw invalid_argument("Atividade ja adicionada");
    }

    // Pode ser adicionada
    atividades->push_back(a);
    quantidadeAtividades++;
}

int Projeto::getQuantidadePessoas() {
    return this->quantidadePessoas;
}

Pessoa** Projeto::getPessoas() {
    return this->pessoas;
}

void Projeto::adicionar(Pessoa* p) {
    // Limite de pessoas atingido
    if (quantidadePessoas >= maximoValor)
        throw overflow_error("Sem espaco disponivel");

    // Pessoa ja previamente adicionada
    for (int i = 0; i < quantidadePessoas; i++) {
        if (pessoas[i] == p)
            throw invalid_argument("Pessoa ja adicionada");
    }

    // Pode ser adicionada
    pessoas[quantidadePessoas] = p;
    quantidadePessoas++;
}
