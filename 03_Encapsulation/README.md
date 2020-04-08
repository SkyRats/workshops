# 3 - Encapsulation

A good habbit to have when programming is to separate your code in modules. One of the modularity principles is the *Data Hiding*, it is useful because it hides the module details from ther modules. So it separates the purpose of your implementation and also retriscts access to other implementation details to any other data structure from the module.

Here in OOP the *Data Hiding* is called *Encapsulation*. To be more clear, it let us hide unecessary details from other classes which are not needed to understand the characteristcs of the class we are working at the moment.

### Access Specifiers

Access specifiers are used for determining or setting the boundary for the availability of class members (data members and member functions) beyond that class.

For example, the class members are grouped into sections, `private` `protected` and `public`. These keywords are called access specifiers which define the accessibility or visibility level of class members.

By default the class members are `private`. So if the visibility labels are missing then by default all the class members are `private`.

In inheritance (we will discuss this later in other topics), it is important to know when a member function in the base class can be used by the objects of the derived class. This is called accessibility and the access specifiers are used to determine this.

* `public` = objects from **any** other class can access
* `private` = access restricted only to objects from the class
* `protected` = access restricted only to objects from the class and its derived classes

`check out Example 1 on "Examples (commented)" section`

### Getters and Setter Methods

Getters and Setters allow you to effectively protect your data. This is a technique used greatly when creating classes. For each variable, a get method will return its value and a set method will set the value.

Check out the **example** below:

```c++
#include <iostream>
using namespace std;

class Employee {
  private:
    int salary; // The salary attribute is private, which have restricted access.

  public:
    void setSalary(int s) {
      salary = s; 
      // The public setSalary() method takes a parameter (s) and 
      // assigns it to the salary attribute (salary = s).
    }
    int getSalary() {
      return salary; 
      // The public getSalary() method returns the value of 
      // the private salary attribute.
    }
};

// Inside main(), we create an object of the Employee class. 
// Now we can use the setSalary() method to set the value of the 
// private attribute to 50000. Then we call the getSalary() 
// method on the object to return the value.

int main() {
  Employee* MrFeather;
  MrFeather.setSalary(50000);
  cout << MrFeather.getSalary();
  return 0;
}
```

### Source File Organization: ".h" and ".cpp" Files

Organization may be something that we could not give so much importance for basic programs like the example above, but when we are making or we are part of a bigger project with hundereds, thousands or even millions of lines of code or classes this is the most important virtue so we can continue developing and sharing this development with other people.

In C++ we organize our files in three main files, the **HEADER** files which have the extension `.h` on their names. so if the name of the file is "example" the header file's name is `example.h`. There's also the **SOURCE** files which have the extension `.cpp`, so the example's source file nasme is `example.cpp`. And finally the code which is going to be the executable program, the `main.cpp`.

**NOTE:** All the .cpp files must be compiled, since they include the header files we don't need to compile the .h files

The same **Example** of the topic above could be separated like this:

**1. Header File**

```c++
#ifndef EMPLOYEE_H // ifndef directive is explained in the topic below
#define EMPLOYEE_H // ifndef directive is explained in the topic below
#include <iostream>
using namespace std;

class Employee {
  private:
    int salary;

  public:
    void setSalary(int s); // method only declared but not implemented
    int getSalary(); // method only declared but not implemented
};
#endif // EMPLOYEE_H // ifndef directive is explained in the topic below
```

**2. Source File**
```c++
#include "Employee.h" // it's necessary to include the "code" of the header

void setSalary(int s) {
      salary = s;   // method implementation
}
int getSalary() {
  return salary;    // method implementation
}
```

**3. Main File**

```c++
#include "Employee.h" // it's necessary to include the "code" of the header
#include <iostream>
using namespace std;

int main() {
  Employee* MrFeather;
  MrFeather.setSalary(50000);
  cout << MrFeather.getSalary();

  return 0;
}
```

### #ifndef Directives

The #ifndef directive has the following syntax:

> #ifndef identifier newline

This directive checks to see if the identifier is not currently defined.

So it is very useful, if not mandatory, for our OOP files in C++, because sometimes we have to include classes which include other common classes, and it is literally a waste of time to include classes more than once (**and it does not build!**). So that's why we use ifndef directives in our files.

When you use the *ifndef* directive properly it defines the class **only** if it was **NOT** already defined before.

* The synthax to use the *ifndef* for a class named "example" is:
```c++
#ifndef EXAMPLE_H
#define EXAMPLE_H

// .
// .
// .
// class definition
// .
// .
// .

#endif
```

### Object Vector

In C++ is possible to create vectors of any type, including of already defined and implemented classes. 

##### Synthax

> <"Type"> *name[Size] 

#### Example

Using the same example of the `employee` class, I could wirte a different `main.cpp`:

```c++
#include "Employee.h"
#include <iostream>
using namespace std;

int main() {
  Employee* MrFeather[2]; // creates a vector of 3 employees

  MrFeather[0].setSalary(50000); // set the salary of the first employee to 50000
  MrFeather[1].setSalary(25000); // set the salary of the second employee to 25000
  MrFeather[2].setSalary(12500); // set the salary of the third employee to 12500

  cout << MrFeather[0].getSalary(); // prints the salary of the first employee
  cout << MrFeather[1].getSalary(); // prints the salary of the second employee
  cout << MrFeather[2].getSalary(); // prints the salary of the third employee

  return 0;
}
```