#include <iostream>
#include <string>

using namespace std;

class Pessoa {
public:
    string nome;
    bool disponivel;
    int horasMensais;

    double getSalarioDiario();
    void imprimir();
};

/** @TODOS: Implementar metodos da classe Pessoa **/

class Atividade {
public:
    string nome;
    int duracao;
    Pessoa *p1 = NULL;
    Pessoa *p2 = NULL;

    Pessoa* getResponsavel();
    bool adicionar(Pessoa *p);
    double getCusto();
    void imprimir();
};

/** @TODOS: Implementar metodos da classe Atividade **/


/** @TODOS: Testar classes no metodo main().

    REMOVER METODO main() ANTES DE ENVIAR AO JUDGE!
**/
/*
int main() {

}
*/
