#include <iostream>

using namespace std;

int main() {
  int i = 5;
  int *p = &i;

  cout << i << endl;
  cout << *p << endl;

  *p = 10;
  cout << *p << endl;
  cout << i << endl;

  return 0;
}
