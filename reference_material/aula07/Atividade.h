#ifndef ATIVIDADE_H
#define ATIVIDADE_H

#include <iostream>
#include <string>
#include <cmath>

#include "Pessoa.h"

using namespace std;

class Atividade {
protected:
    string nome;
    Pessoa** pessoas;
    int horasNecessarias;
    int quantidade;
    int maximoPessoas;

public:
    Atividade(string nome, int horasNecessarias, int maximoPessoas);
    ~Atividade();
    int getHorasNecessarias();
    int getQuantidade();
    Pessoa** getPessoas();

    bool adicionar(Pessoa* p);
    int getDuracao();
    void imprimir();
  };

#endif // ATIVIDADE_H
