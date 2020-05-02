#include "Employee.h"

#include <iostream>
using namespace std;

int main() {
  Employee* MrFeather[3]; // creates a vector of 3 employees

  MrFeather[0] = new Employee();
  MrFeather[1] = new Employee();
  MrFeather[2] = new Employee();

  MrFeather[0]->setSalary(50000); // set the salary of the first employee to 50000
  MrFeather[1]->setSalary(25000); // set the salary of the second employee to 25000
  MrFeather[2]->setSalary(12500); // set the salary of the third employee to 12500

  cout << MrFeather[0]->getSalary() << endl; // prints the salary of the first employee
  cout << MrFeather[1]->getSalary() << endl; // prints the salary of the second employee
  cout << MrFeather[2]->getSalary() << endl; // prints the salary of the third employee

  return 0;
}