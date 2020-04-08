#include <iostream>

using namespace std;

int main() {
  int a1[] = {1, 2, 5};

  int *p = a1;

  cout << p[0] << endl;
  cout << p[2] << endl;

  // Arranjo de ponteiros

  int *a2[10]; // arranjo para 10 ponteiros de int

  int i = 0;
  a2[0] = &i;  // colocando o endereço de i na posição 0

  *a2[0] = 10; // alternado o valor do inteiro em i para 10

  cout << i << endl;

  return 0;
}
