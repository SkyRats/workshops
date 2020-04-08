#include <iostream>

using namespace std;

int pentagonal(int num){
    int sum = 0;
    int sum2 = 1;

    for(int i = 0; i < num; i++){
        sum2 += sum;
        sum += 5;
    }

    return sum2;
}

int main(){
    int num;

    cout << "Digit a number: ";
    cin >> num;

    cout << "The pentagonal number is: " << pentagonal(num) << endl;

    return 0;
}