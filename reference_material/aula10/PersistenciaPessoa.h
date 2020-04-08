#ifndef PERSISTENCIAPESSOA_H
#define PERSISTENCIAPESSOA_H

/*  Faca os includes necessarios!
 */

class PersistenciaPessoa {
public:
    PersistenciaPessoa(string arquivo);
    virtual ~PersistenciaPessoa();

    void inserir(Pessoa* p);
};

#endif // PERSISTENCIAPESSOA_H
