#include <iostream>

using namespace std;

int factorial(int num){
    int n = num - 1;
    while(n > 1){
        num *= n;       // the same as 'num = num * n'
        n--;            // the same as 'n = n - 1'
    }
    return num;
}

int main(){
    int num;

    cout << "Input n: ";
    cin >> num;

    cout << "factorial of " << num << " is " << factorial(num) << endl;

    return 0;
}