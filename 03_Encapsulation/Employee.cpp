#include "Employee.h"

#include <iostream>
using namespace std;

void Employee::setSalary(int s){
    salary = s;
      // The public setSalary() method takes a parameter (s) and 
      // assigns it to the salary attribute (salary = s).
}

int Employee::getSalary(){
      return salary; 
      // The public getSalary() method returns the value of 
      // the private salary attribute.
}