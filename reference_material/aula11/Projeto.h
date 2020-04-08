#ifndef PROJETO_H
#define PROJETO_H

#include <string>
#include <vector>
#include "Atividade.h"
#include "Pessoa.h"

using namespace std;

class Projeto {
public:
    Projeto(string nome, int maximoValor);
    ~Projeto();

    int getDuracao();
    int getQuantidadePessoas();
    vector<Atividade*>* getAtividades();
    Pessoa** getPessoas();

    void adicionar(Atividade* a);
    void adicionar(Pessoa* p);
private:
    string nome;
    int maximoValor;
    int quantidadeAtividades;
    int quantidadePessoas;
    vector<Atividade*>* atividades;
    Pessoa** pessoas;
};

#endif // PROJETO_H
