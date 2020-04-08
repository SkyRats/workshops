# 5 - Inheritance and Polymorphism

Inheritance is one of the essential characteristcs of Object Oriented Programming. It is the capability of a class to derive properties and characteristics from another class.

* **Sub Class**: The class that inherits properties from another class is called *Sub class* or *Derived Class*.
* **Super Class**:The class whose properties are inherited by sub class is called *Base Class* or *Super class*.

### Why and when use it?

Consider a group of vehicles. You need to create classes for **Bus**, **Car** and **Truck**. The methods `fuelAmount()`, `capacity()`, `applyBrakes()` will be same for all of the three classes. 

If we create these classes avoiding inheritance then we have to write all of these functions in each of the three classes as shown in below figure:

<img 
    src="images/inheritance.png"
    alt="No inheritance"
/>

You can clearly see that above process results in duplication of same code 3 times. This increases the chances of error and data redundancy. To avoid this type of situation, inheritance is used. 

If we create a class `Vehicle` and write these three methods (functions) in it and inherit the rest of the classes from the vehicle class, then we can simply avoid the duplication of data and increase re-usability. 

Look at the below diagram in which the three classes are inherited from vehicle class:

<img
    src="images/inheritance2.png"
    alt="Inheritance in"
/>

Using inheritance, we have to write the functions only one time instead of three times as we have inherited rest of the three classes from base class(Vehicle).

### Implementing inheritance in C++

#### Synthax

```c++
class subclass_name : access_mode base_class_name
{
  //body of subclass
};
```

Here, `subclass_name` is the name of the sub class, `access_mode` is the mode in which you want to inherit this sub class for example: `public`, `private` etc. And `base_class_name` is the name of the base class from which you want to inherit the sub class.

**Note:** A derived class **doesn’t** inherit access to `private` data members. However, it does inherit a full parent object, which contains any private members which that class declares.

### Vehicle class example

Using the example of the `Vehicle` class as in the image above, but instead of implementing the methods `fuelAmount()`, and `capacity()` we are going to make them turn into **Getter Methods** and include atributtes in the `Vehicle` class.

We could implemented it like this:

**1. Vehicle.h**
```c++
#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle{
    public:
        Vehicle();
        ~Vehicle();
        int getFuelAmount();
        int getCapacity();

        void applyGas(); // method that increases acceleration value in 1 unit
        void applyBreaks(); // method that decreases the acceleration value in 1 unit

        void setPassengers(int x);

    protected:
        int fuel;
        int nPassengers;
        int acceleration;
};

#endif // VEHICLE_H
```

**2. Vehicle.cpp**
```c++
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
```

The idea here is that the `Bus` class is only to illustrate that we could specify characteristics of a Bus. The requirements and classes that you will implement will depend exclusively of your project.

**3. Bus.h**

```c++
#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"
#include <string>

class Bus : public Vehicle{
    public:
        Bus();
        ~Bus();

        void setDriverName(string name);
        string getDriverName();

        void setTicketPrice(int p);
        int getTicketPrice();

    private:
        string name;
        int p;
};

#endif
```

**4. Bus.cpp**

```c++
#include "Bus.h"
#include <iostream>

using namespace std;

Bus::Bus(){
    cout << "BUS CREATED" << endl;

    name = "UNNAMED DRIVER";
    p = 0;
}

void Bus::setDriverName(string name){
    this->name  = name;
}

string Bus::getDriverName(){
    return name;
}

int Bus::getTicketPrice(){
    return p;
}

void Bus::setTicketPrice(int p){
    this->p = p;
}

Bus::~Bus(){
    cout <<"BUS DESTROYED" << endl;
}
```