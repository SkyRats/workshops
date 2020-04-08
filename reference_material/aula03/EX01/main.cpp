#include <iostream>
using namespace std;

class Lampada {
public:
  bool acesa = false;
  void ligar();
  void desligar();
  void imprimir();
};

void Lampada::ligar() {
  this->acesa = true;
}

void Lampada::desligar() {
  this->acesa = false;
}

void Lampada::imprimir() {
  cout << this->acesa << endl;
}

int main() {
  Lampada *l1 = new Lampada;
  Lampada *l2 = new Lampada;
  l1->imprimir();
  l1->ligar();
  l1->imprimir();
  cout << l1->acesa << endl;

  l2->ligar();
  l2->imprimir();
  l2->desligar();
  l2->imprimir();
  return 0;
}
