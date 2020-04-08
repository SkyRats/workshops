#include <iostream>
using namespace std;

int multiplicar (int x, int y) {
	return x * y;
}

int main() {
	int x = 5, y = 3;
	cout << multiplicar (x, y) << endl;
	return 0;
}
