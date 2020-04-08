#include <iostream>

using namespace std;

int main() {
  char c = 'a';

  char *p1 = &c;
  char *p2 = &c;
  char *p3 = p1;

  cout << *p3 << endl;

  *p3 = 'b';

  cout << c << endl;

  return 0;
}
