#include <iostream>

using namespace std;

int main (int argc, char** argv) {
  int i = 100;
  double j = 5.5;

  cout << &i << endl;
  cout << &j << endl;

  int *p1;
  double *p2;

  p1 = &i;
  p2 = &j;

  cout << p1 << endl;
  cout << p2 << endl;

  return 0;
}
