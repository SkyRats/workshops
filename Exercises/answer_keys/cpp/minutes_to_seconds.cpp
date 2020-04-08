#include <iostream>

using namespace std;

int convert(int num);

int main(){
    int num;

    cout << "Write the number in minutes: ";
    cin >> num;

    cout << convert(num) << endl;;

    return 0;
}

int convert(int num){ // this variable num is a copy of the variable num in int main()
    return num * 60;
}