#include "AtividadeComSupervisor.h"
#include "Atividade.h"
#include "Pessoa.h"

AtividadeComSupervisor::AtividadeComSupervisor(string nome, int horasNecessarias,
    int maximoPessoas, Pessoa* supervisor) : Atividade (nome),
    horasNecessarias (horasNecassarias), maximoPessoas (maximoPessoas),
    supervisor (supervisor)
{

}

AtividadeComSupervisor::~AtividadeComSupervisor()
{

}

Pessoa AtividadeComSupervisor::getSupervisor()
{

}


//Implemente os metodos

