#ifndef ATIVIDADE_H
#define ATIVIDADE_H

#define NUMERO_MAXIMO_VALORES 10

#include "Pessoa.h"
#include <cmath>
#include <iostream>

using namespace std;

class Atividade {
private:
    string nome;
    int horasNecessarias;
    int maxValores;
    int quantidade = 0;
    Pessoa* pessoas[NUMERO_MAXIMO_VALORES];

public:
    Atividade(string nome, int horasNecessarias, int maxValores);
    ~Atividade();

    string getNome();
    int getHorasNecessarias();
    int getQuantidade();
    int getDuracao();

    bool adicionar(Pessoa* p);
    void imprimir();

    Pessoa* getLider() const;
};

#endif // ATIVIDADE_H
