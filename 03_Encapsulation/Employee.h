#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
  private:
    int salary; // The salary attribute is private, which have restricted access.

  public:
    void setSalary(int s);
    int getSalary();
};

#endif // EMPLOYEE_H