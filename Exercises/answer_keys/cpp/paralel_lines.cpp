#define MAX 3

#include <iostream>

using namespace std;

bool lines_are_paralel(int l1[], int l2[]);

int main(){
    int a, b, c, d, e, f;

    cout << "Digit the values for 'a', 'b' and 'c' of the first line ax + b = c: " << endl;
    cin >> a; cin >> b; cin >> c;

    cout << "Digit the values for 'd', 'e' and 'f' of the second line dx + e = f: " << endl;
    cin >> d; cin >> e; cin >> f;

    int l1[MAX] = {a, b, c};
    int l2[MAX] = {d, e, f};

    if(lines_are_paralel(l1, l2))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}

bool lines_are_paralel(int l1[], int l2[]){
    if(l1[0] == l2[0])
        return true;
    else
        return false;
}