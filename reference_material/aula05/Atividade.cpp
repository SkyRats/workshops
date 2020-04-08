#include "Atividade.h"

#include <iostream>

using namespace std;

string Atividade::getNome() {
    return this->nome;
}

int Atividade::getHorasNecessarias() {
    return this->horasNecessarias;
}

int Atividade::getQuantidade() {
    return this->quantidade;
}

int Atividade::getDuracao() {
    double totalHoras = 0;

    if (quantidade == 0)
        return -1;

    for (int i = 0; i < quantidade; i++)
        totalHoras += pessoas[i]->getHorasDiarias();
    return ceil(horasNecessarias/totalHoras);
}

bool Atividade::adicionar(Pessoa* p) {
    if (quantidade >= maxValores)
        return false;

    pessoas[quantidade] = p;
    quantidade++;
    return true;
}

void Atividade::imprimir() {
    cout << this->nome << " - " << this->getDuracao() << " dia(s) estimado(s)" << endl;
    for (int i = 0; i < quantidade; i++)
        pessoas[i]->imprimir();
}
Atividade::Atividade(string nome, int horasNecessarias, int maxValores) : nome (nome), horasNecessarias (horasNecessarias), maxValores (maxValores)
{

}
Atividade::~Atividade()
{
    cout << "Atividade " << this->nome << " de tamanho " << this->maxValores << " com " << this->quantidade << " pessoa(s) destruida" << endl;

    for(int i = 0; i < maxValores; i++){
        delete pessoas[i];
    }
}
Pessoa Atividade::getLider() const
{
    int maior =  pessoas[0];
    int ponteiro = 0;

    for(int i = 1; int < maxValores; i++){
        if(pessoas[i]->getHorasDiarias() >= maior){
            if(pessoas[i] == maior){
            }else{
                ponteiro = i;
                maior = pessoas[i]->getHorasDiarias();
            }
        }
    }

    return pessoas[ponteiro];
}
