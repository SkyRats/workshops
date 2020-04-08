#include <iostream>

using namespace std;

void trocar(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}

void trocar1(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void trocar2(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


int main() {
  int a = 1;
  int b = 2;

  trocar(a, b);
  cout << "a: " << a << " b: " << b << endl;

  a = 1, b = 2;

  trocar1(a, b);
  cout << "a: " << a << " b: " << b << endl;

  a = 1, b = 2;

  trocar2(&a, &b);
  cout << "a: " << a << " b: " << b << endl;

  return 0;
}
