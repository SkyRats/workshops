#include "AtividadeComSupervisor.h"

AtividadeComSupervisor::AtividadeComSupervisor(string nome, int horasNecessarias, int maximoPessoas, Pessoa* supervisor) :
                                               Atividade(nome, horasNecessarias, maximoPessoas),  supervisor(supervisor) {
    this->horasNecessarias += 1 + horasNecessarias/4;
}

AtividadeComSupervisor::~AtividadeComSupervisor() {
    //dtor
}

Pessoa* AtividadeComSupervisor::getSupervisor() {
    return this->supervisor;
}
