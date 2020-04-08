#include <iostream>

using namespace std;

int addition(int a, int b){
    return a + b;
}

int main(){
    int a;
    int b;

    cout << "Input a: ";
    cin >> a;
    cout << "input b: ";
    cin >> b;

    cout << "(" << a << ", " << b << ")" << endl;
    cout << "addition: " << addition(a, b) << endl;
    return 0;
}