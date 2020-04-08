#ifndef ATIVIDADECOMSUPERVISOR_H
#define ATIVIDADECOMSUPERVISOR_H

/* Inclua os arquivos necessarios.
 * A classe eh filha de Atividade.
 * Altere e/ou inclua os atributos e metodos necessarios nesta
 * definicao conforme necessario */


class AtividadeComSupervisor : public Atividade {
  public:
    AtividadeComSupervisor(string nome, int horasNecessarias,
                            int maximoPessoas, Pessoa* supervisor);
    ~AtividadeComSupervisor();
    Pessoa* getSupervisor();
};

#endif // ATIVIDADECOMSUPERVISOR_H
