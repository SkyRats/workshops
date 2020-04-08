#ifndef PROJETO_H
#define PROJETO_H

/* Fazer includes necessarios!
 */

class Projeto {
  public:
    Projeto(string nome, int maximoAtividades);
    ~Projeto();

    int getDuracao();
    int getQuantidade();
    bool adicionar(Atividade* a);

  private:
    /* Adicionar atributos necessarios */
};

#endif // PROJETO_H
