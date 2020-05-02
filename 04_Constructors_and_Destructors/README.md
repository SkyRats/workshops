# 4 - Constructors and Destructors

*Constructors* are special *class functions* (methods) which performs **initialization** of every object. The *Compiler* calls the *Constructor* whenever an object is created, allocating memory to store the object. Constructors initialize values to object members after storage is allocated to the object.

Contructors are called automatically by the compiler and they also can be define **with** or **without** *Arguments*.
It is possible to have more than one *Constructor*.

*Destructors* on the other hand are (methods) used to destroy the class object.

### Constructor Declaration

A constructor is basically another *method* from a *class*, the only things that differ from any other method are:

* It doesn't have a return type (since it doesn't return anything)
* It can have parameters (arguments)

In C++ if the *Constructor* was not defined, the compiler defines the *Standard Constructor*.

Using the same example with the `Employee class` the *Standard Constructor* defined by the *Compiler* was:

```c++
#include <iostream>
using namespace std;

class Employee {
  private:
    int salary;

  public:
    Employee(); // Contructor declaration
    ~Employee(); // Destructor declaration
    void setSalary(int s);
    int getSalary();
};
```

In the class above we can see that different from the `Employee.h` above, which we didn't declared niether the Constructor and Destructor, and as any other method they now have to be implemented.

### Constructor Implementation

There are **two** ways to implement a *Constructor* in C++:

The examples below are a version of the `Employee class` with **one** attribute (`int` `salary`).

1. Option 1

```c++
Employee::Employee(int salary){
  this->salary = salary;
}
```

* We use `this` to differ the **attribute** from the **parameter**

2. Option 2 (recommended)

```c++
Employee::Employee(int salary) : salary (salary){
}
```
* It still uses the attribute's name as parameters
  * It makes reading easier for who **uses** the constructor

3. Option 3 - Use Python! Python is way more **coxa**


```python
class Employee:
  def __init__(self, name, salary):
    self.__salary = salary
    self.name = name
    
  def set_salary(self, new_value):
    self.__salary = new_value
  
  def __get_salary(self, new_value):
    return self.__salary

  def present(self):
    print("Hey there, name is {} and I earn {}".format(self.name, self.__salary))
```


### Calling Constructors

To call the Constructor above (with the `salary`parameter), we should have the `main.cpp` like this:

```c++
#include "Employee.h"
#include <iostream>
using namespace std;

int main() {
  Employee* MrFeather(50000);

  cout << MrFeather.getSalary(); // it prints 50000

  return 0;
}
```

### NULL

The macro NULL is an implementation-defined null pointer constant, which may be:

* An integral constant expression rvalue of integer type that evaluates to zero
* An integer literal with value zero, or a prvalue of type std::nullptr_t

Basically a pointer that points to **NO** value.

If you want more info about NULL pointer check this <a href="https://en.cppreference.com/w/cpp/types/NULL">reference</a>

### Destructors

Similarly to the *Constructors*, there are methods called *Destrcutors*, which are called automatically when it is asked to deallocate an object. So being, a *Desctructor* must free the computational resources allocated previously by the *Object*.

To declare a *Destructor* it is pretty simple, because it does not have any parameters and it doesn't return anything. So basically you have to write the class's name with a `~` in the beginning (We already have in an example above a declaration of the `~Employee();`). 

Check out the example below where we implement the `~Employee();`:



```c++
Employee::~Employee(int salary){
}
```
So now that we already have our *Destructor*, the way to "use" it, is by typing the `delete` command, check the `main.cpp` below:

```c++
#include "Employee.h"
#include <iostream>
using namespace std;

int main() {
  Employee* MrFeather(50000); // we create our object here

  cout << MrFeather.getSalary(); // it prints 50000

  delete MrFeather; // we destroy our object here

  return 0;
}
```

It is sometimes common to print that the object is being **destroyed**, so you could for example put it in the destructor's implementation like this:

```c++
Employee::~Employee(int salary){
  cout << "OBJECT DESTROYED" << endl;
}
```

### Memory Management

There are two types of *Memory Allocations* and usually who decides which is going to be used is the **compiler**.

* **Static Allocation**
  * It creates the object in the variable declaration
  * It destroys the object when the scope ends
  * Problems:
    * We not always know **in compilation time** how many objects are going to be needed
    * We do not necessarily want the object to be destroyed in the end of the scope
    * Example: when the object created was stored in an atributte of another object

<br/>

* **Dynamic Allocation**
  * It uses a special area in the memory called **heap** / **free store** / **dynamic memory**
  * The programmer must manage the memory
  * **HEAP** Allocation (`new`)
    * Returns an identifier to the created object
    * Calls the *Constructor*
  * **HEAP** Deallocation (`delete`)
    * Calls the *Destructor*
  * **Dynamic Vectors**. Check the example below:

    ```c++
    // Allocating
    
    #define MAX 100
    
    int integers = new int[MAX];
    ```
    ```c++
    // Deallocating
    
    delete[] integers;
    ```
  
> Every time that something is allocated (`new`), it must be deallocated at some point (`delete`)!

### Constants

Constants refer to fixed values that the program may not alter and they are called **literals**. They are treated just like regular variables except that their values cannot be modified after their definition.

To declare a variable as a constant you just have to put `const` before the veriable:

```c++
const int number = 5;

// if you try to change the value of the constant 
// it gives you a compilation error, for example:

number = 4; // COMPILATION ERROR
```