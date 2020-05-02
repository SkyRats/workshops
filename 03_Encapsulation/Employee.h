#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee {
  private:
    int salary; // The salary attribute is private, which have restricted access.

  public:
    Employee();
    ~Employee();

    void setSalary(int s);
    int getSalary();
};

#endif // EMPLOYEE_H