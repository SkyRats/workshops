// This program has the goal to print a "Ladder" of chars that 
// is chosen by the user. The height of the "Ladder" also
// is chosen by the user.

#include <iostream>

using namespace std;

void ladder(int h, char d){
    for(int i = 1; i <= h; i++){
        for(int k = 0; k < i; k++){
            cout << d << " ";
        }
        cout << endl;
    }
}

int main(){
    int height;
    char digit;

    cout << "Input a height value and a type of digit: ";
    cin >> height;
    cin >> digit;

    cout << endl; // just skips a line for better visualization

    ladder(height, digit);
}