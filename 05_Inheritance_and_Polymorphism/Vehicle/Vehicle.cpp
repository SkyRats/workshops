#include "Vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle(){
    cout << "This is a vehicle." << endl;
    
    fuel = 100; // vehicle always starts with a full tank
    acceleration = 0;
    nPassengers = 1; // vehicle start with at least one seat (driver) 
}

int Vehicle::getFuelAmount(){
    return fuel;
}

int Vehicle::getCapacity(){
    return nPassengers;
}

void Vehicle::applyGas(){
    acceleration++;
    fuel -= acceleration;
}

void Vehicle::applyBreaks(){
    acceleration--;
}

void Vehicle::setPassengers(int x){
    nPassengers = x;
}

Vehicle::~Vehicle(){
    cout << "VEHICLE DESTROYED" << endl;
}