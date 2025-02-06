#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>


class Employee {
  public:

    Employee(); //Default Constructor
    Employee(const std::string &firstName,
             const std::string &lastName,
             int salary);
    ~Employee();
  
    std::string getFirstName() const;
    void setFirstName(const std::string &fN); //Pass variable of namesake

  
    std::string getLastName() const;
    void setLastName(const std::string &lN); //Pass variable of namesake
  
  

    int getSalary();
    void setSalary(int sal); //Pass variable of namesake

    int giveRaise();


  private:
  
  std::string firstName;
  std::string lastName;
  int salary;

};
  
#endif
