#ifndef PROJETO_H
#define PROJETO_H

#include <string>
#include "Atividade.h"

using namespace std;

class Projeto {
public:
    Projeto(string nome, int maximoValor);
    ~Projeto();

    int getDuracao();
    int getQuantidadeAtividades();
    Atividade** getAtividades();

    bool adicionar(Atividade* a);

private:
    string nome;
    int maximoValor;
    int quantidadeAtividades;
    Atividade** atividades;
};

#endif // PROJETO_H
