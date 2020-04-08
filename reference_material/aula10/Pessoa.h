#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

using namespace std;

class Pessoa {
public:
    Pessoa(string nome, double valorPorHora, int horasDiarias);
    virtual ~Pessoa();

    virtual string getNome();
    virtual double getValorPorHora();
    virtual int getHorasDiarias();

    virtual double getCusto(int dias);
    virtual void imprimir();

protected:
    string nome;
    double valorPorHora;
    int horasDiarias;

};

#endif // PESSOA_H
