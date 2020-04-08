#include "Vehicle.h"
#include <iostream>

using namespace std;

int main(){
    Vehicle* v = new Vehicle();

    cout << "Fuel Level: " << v->getFuelAmount() << endl;
    
    cout << "Insert the number of passengers of your Vehicle: ";
    int x;
    cin >> x;
    cout << "Previous number of Passengers: " << v->getCapacity() << endl;
    v->setPassengers(x);
    cout << "Current number of Passengers:";
    cout << v->getCapacity() << endl;

    cout << "Accelerating" << endl;

    for(int k = 0; k < 3; k++)
        cout << "." << endl;

    v->applyGas();
    cout << "Fuel Level: " << v->getFuelAmount() << endl;

    cout << "Accelerating" << endl;

    for(int k = 0; k < 3; k++)
        cout << "." << endl;

    v->applyGas();
    cout << v->getFuelAmount() << endl;

    cout << "Breaking" << endl;

    for(int k = 0; k < 3; k++)
        cout << "." << endl;
        
    v->applyBreaks();
    cout << "Fuel Level: " << v->getFuelAmount() << endl;

    cout << "Breaking" << endl;

    for(int k = 0; k < 3; k++)
        cout << "." << endl;
        
    v->applyBreaks();
    cout << "Fuel Level: " << v->getFuelAmount() << endl;

    cout << "Vehicle is stopped." << endl;

    return 0;
}