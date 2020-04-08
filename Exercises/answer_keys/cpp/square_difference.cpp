#include <cmath>
#include <iostream>

using namespace std;

int sqrdif(int r){
    int bigger_square_area, smaller_square_area = 0;

    bigger_square_area = 2*r*2*r;
    smaller_square_area = pow(sqrt(2)*r, 2);
}

int main(){
    int radius;

    cout << "Give the radius of the circle: ";
    cin >> radius;

    cout << "The difference of the areas of the squares is: " << sqrdif(radius) << endl;

    return 0;
}