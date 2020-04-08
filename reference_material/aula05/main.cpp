#include "Pessoa.h"
#include "Atividade.h"
#include <iostream>

using namespace std;

int main() {
    // Implementar testes

    Pessoa* joao = new Pessoa("Joao", 5);
    Pessoa* maria = new Pessoa("Maria", 8);
    Pessoa* tiago = new Pessoa("Tiago", 6);

    Atividade* ep = new Atividade("EP", 50, 2);
    ep->adicionar(joao);
    ep->adicionar(maria);
    ep->adicionar(tiago);
    ep->getDuracao();
    //ep->imprimir();

    delete ep;

    return 0;
}
