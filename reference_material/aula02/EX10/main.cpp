#include <iostream>
using namespace std;

int main() {
  int entrada[10];
  cout << "Digite 10 numeros" << endl;

  for (int i = 0; i < 10; i++)
    cin >> entrada[i];

  int soma = 0;

  for (int i = 0; i < 10; i++) {
    if (entrada[i] > 0)
      soma += entrada[i];
  }

  cout << "Valor: " << soma;
  return 0;
}
