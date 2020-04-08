#ifndef ATIVIDADE_H
#define ATIVIDADE_H

#include <iostream>
#include <string>
#include <cmath>

#include "Pessoa.h"

using namespace std;

class Atividade {
  private:

    Pessoa** pessoas;

    int quantidade = 0;


  public:
    Atividade(string nome, int horasNecessarias, int maximoPessoas);
    ~Atividade();
    int getHorasNecessarias();
    int getQuantidade();

    bool adicionar(Pessoa* p);
    int getDuracao();
    void imprimir();

  protected:
    string nome;
    int horasNecessarias;
    int maximoPessoas;

  };

#endif // ATIVIDADE_H
