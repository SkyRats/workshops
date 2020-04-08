#include <iostream>
using namespace std;

int main() {
  int i,J,k;
  int l[10];
  cout << "Digite 10 numeros" << endl;
  for (i=0;i<10;    i++)
  cin >>l[i]; k= 0;
    for(J =0;J < 10;J++) {
if (l[J]> 0) k +=l[J];}

  cout << "Valor: " << k;
    return 0;
}
