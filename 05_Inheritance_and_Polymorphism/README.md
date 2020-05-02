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

### Polymorphism

The word **polymorphism** means having many forms. Typically, polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.

C++ polymorphism means that a call to a member function will cause a different function to be executed depending on the type of object that invokes the function.

For example:

```c++
#include <iostream> 
using namespace std;
 
class Shape {
   protected:
      int width, height;
      
   public:
      Shape( int a = 0, int b = 0){
        width = a;
        height = b;
      }
      int area() {
        cout << "Parent class area: " <<endl;
        return 0;
      }
};

class Rectangle: public Shape {
   public:
      Rectangle( int a = 0, int b = 0) : Shape(a, b) { }
      
      int area () { 
         cout << "Rectangle class area :" <<endl;
         return (width * height); 
      }
};

class Triangle: public Shape {
   public:
      Triangle( int a = 0, int b = 0):Shape(a, b) { }
      
      int area () { 
         cout << "Triangle class area :" <<endl;
         return (width * height / 2); 
      }
};

int main() {
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);

   // store the address of Rectangle
   shape = &rec;
   
   // call rectangle area.
   shape->area();

   // store the address of Triangle
   shape = &tri;
   
   // call triangle area.
   shape->area();
   
   return 0;
}
```

### Cast

A cast is a special operator that forces one data type to be converted into another.

An exemple of Cast in C or C++ can be like this: 

```c++
float b = 10.5;
int a = (int) b;
```

#### Cast Hierarchy

* Upcast
    * Converts from a derived class to a base class
    * Implicit conversion
    * Subclasses have at least the same methods that their derived classes
* Downcast
    * Converts from a Subclass to a derived class
    * Explicit conversion
    * Not always we can use the object with derived class's type

There are two ways that we can cast objects: **Static** and **Dynamic**.

#### Static Cast

##### Syntax
 > new_type *newPtr =  static_cast< new_type >(ptr);

Here I'm just going to give you an example of `static_cast`, but it importante to say that it is an UNSAFE method.

```c++
class Vehicle {/*implementation*/};

class Bus : class Vehicle {/*implementation*/};

void f(Bus* v1, Vehicle* v2){
    
    Vehicle* v3 = static_cast<Vehicle*>(v1); // safe conversion because
                                             // Bus have all fields and 
                                             // methods as Vehicle

    
    Bus* v4 = static_cast<Bus*>(v2);    // Unsafe conversion because
                                        // Bus have fields and methods
                                        // that re not in Vehicle
}

Vehicle* v = new Vehicle();

Bus* b = static_cast<Bus*>(v);
```

It is unsafe because it doesn't check in runtime if the conversion is valid. For example:

You can find more information about static cast [here](https://docs.microsoft.com/en-us/cpp/cpp/static-cast-operator?view=vs-2019)


#### Dynamic Cast

##### Syntax
 > new_type *newPtr =  dynamic_cast< new_type >(ptr);

**Dynamic casting** is, primarily, used to safely downcast, but it can also be used for upcasting.

It is important to say that `dynamic_cast` checks consistency at runtime. Consequently, it is slower than `static_cast`.

Using the example of the classes above - `Shape`, `Rectangle` and `Triangle` - we're going to show how *dynamic casting* can be implemented, check it out in `Examples` directory


> To use dynamic_cast<new_type>(ptr) the base class should contain at least one virtual method.