#include <iostream>

using namespace std;

class Pessoa {
public:
  string nome;
  bool disponivel;
  int horasDiarias;
  void setNome(string nome);
  void setDisponivel(bool disponivel);
  void setHorasDiarias (int horasDiarias);

  bool isDisponivel();
  int getHorasDiarias();

  void imprimir();
};

void Pessoa::setNome (string nome) {
  this->nome = nome;
}

void Pessoa::setDisponivel (bool disponivel) {
  this->disponivel = disponivel;
}

void Pessoa::setHorasDiarias (int horasDiarias) {
  this->horasDiarias = horasDiarias;
}

bool Pessoa::isDisponivel() {
  return disponivel;
}

int Pessoa::getHorasDiarias() {
  return horasDiarias;
}

void Pessoa::imprimir() {
  cout << nome << ": ";
  if (!disponivel) {
    cout << "in";
  }
  cout << "disponivel - " << horasDiarias << " hora(s) por dia" << endl;
}

int main() {
    /*
     * Teste as classes aqui.
     */

    return 0;
}
