#ifndef ATIVIDADECOMSUPERVISOR_H
#define ATIVIDADECOMSUPERVISOR_H

#include "Pessoa.h"
#include "Atividade.h"
#include <string>

using namespace std;

class AtividadeComSupervisor: public Atividade {
private:
    Pessoa* supervisor;

public:
    AtividadeComSupervisor(string nome, int horasNecessarias, int maximoPessoas, Pessoa* supervisor);
    ~AtividadeComSupervisor();
    Pessoa* getSupervisor();
};

#endif // ATIVIDADECOMSUPERVISOR_H
