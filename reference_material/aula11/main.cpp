#include <iostream>
#include "Pessoa.h"
#include "Atividade.h"
#include "Projeto.h"

using namespace std;

int main() {
    // Implemente os testes necessarios

    Projeto* p = new Projeto("projeto 1", 3);
    Atividade* a1 = new Atividade("EP1", 30, 2);
    Atividade* a2 = new Atividade("EP2", 50, 2);
    Pessoa* p1 = new Pessoa("Fulano", 5);
    Pessoa* p2 = new Pessoa("Ciclano", 4);

    p->adicionar(a1);
    p->adicionar(a2);
    p->adicionar(p1);
    p->adicionar(p2);

    return 0;
}
