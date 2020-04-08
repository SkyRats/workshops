#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
  private:
    string nome;
    int horasDiarias;

  public:
    Pessoa(string nome, int horasDiarias);
    ~Pessoa();
    int getHorasDiarias();

    void imprimir();
};

#endif // PESSOA_H
