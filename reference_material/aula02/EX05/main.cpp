#include <iostream>

using namespace std;

int main() {
  int i = 100;
  int *p1 = &i;

  int **p2;
  p2 = &p1;

  cout << i << endl;
  cout << *p1 << endl;
  cout << **p2 << endl;

  return 0;
}
