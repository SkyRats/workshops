#include <iostream>

using namespace std;

int main() {
  int *p1; // endere�o indefinido

  cout << *p1 << endl; // Ops... Problema!

  int *p2; // endere�o indefinido
  p2 = NULL; // nenhum valor

  if (p2 == NULL) { // � poss�vel testar
    cout << "Null" << endl;
  }

  return 0;
}
