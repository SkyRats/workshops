#include <iostream>

using namespace std;

bool point_within_triangle(int c1[], int c2[], int c3[], int c4[]);

int main(){
    int cd1[2], cd2[2], cd3[2], cd4[2]; // each coordinate is a vector with size 2

    cout << "Give the coordinates of the 1 dot: " << endl;
    cin >> cd1[0]; cin >> cd1[1];

    cout << "Give the coordinates of the 2 dot: " << endl;
    cin >> cd2[0]; cin >> cd2[1];

    cout << "Give the coordinates of the 3 dot: " << endl;
    cin >> cd3[0]; cin >> cd3[1];

    cout << "Give the coordinates of the 4 dot: " << endl;
    cin >> cd4[0]; cin >> cd4[1];

    cout << "Your coordinates are: "
    << "[" << cd1[0] << ", " << cd1[1] << "] "
    << "[" << cd2[0] << ", " << cd2[1] << "] "
    << "[" << cd3[0] << ", " << cd3[1] << "] " 
    << "[" << cd4[0] << ", " << cd4[1] << "] " << endl;

    if(point_within_triangle(cd1, cd2, cd3, cd4))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

bool point_within_triangle(int c1[], int c2[], int c3[], int c4[]){
    int init_area = 0;
    int new_area = 0;

    init_area = (c1[0]*c2[1]) - (c1[1]*c2[0]) + (c2[0]*c3[1]) - (c2[1]*c3[0]) + (c3[0]*c1[1]) - (c3[1]*c1[0]);

    new_area = (c4[0]*c2[1]) - (c4[1]*c2[0]) + (c2[0]*c3[1]) - (c2[1]*c3[0]) + (c3[0]*c4[1]) - (c3[1]*c4[0]);
    new_area += (c1[0]*c4[1]) - (c1[1]*c4[0]) + (c4[0]*c3[1]) - (c4[1]*c3[0]) + (c3[0]*c1[1]) - (c3[1]*c1[0]);
    new_area += (c1[0]*c2[1]) - (c1[1]*c2[0]) + (c2[0]*c4[1]) - (c2[1]*c4[0]) + (c4[0]*c1[1]) - (c4[1]*c1[0]);

    if(new_area == init_area){
        return true;
    }else{
        return false;
    }
}