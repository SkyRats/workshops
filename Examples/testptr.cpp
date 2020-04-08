#include <iostream>

using namespace std;

int main(){
    int x = 2;
    int* ptr = &x;

    cout << endl;

    cout << &x << endl;
    cout << ptr << endl;
    cout << *ptr << endl;

    cout << endl;

    return 0;
}