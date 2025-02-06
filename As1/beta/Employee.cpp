#include "Employee.h"
#include <iostream>

//Static Member Variables


//Default Constructor
Employee::Employee() : firstName(""), lastName(""), salary(0) {}


Employee::Employee(const std::string &fN, const std::string &lN, int sal):
  firstName(fN),
  lastName(lN),
  salary(sal) {}


//Destructor
Employee::~Employee(){
  std::cout << "Employee's contract terminated." << std::endl;
}

//Getter & Setters
std::string Employee::getFirstName() const {return firstName;}
void Employee::setFirstName(const std::string &fN){
  firstName = fN;}


std::string Employee::getLastName() const {return lastName;}
void Employee::setLastName(const std::string &lN){
  lastName = lN;}


int Employee::getSalary() {return salary;}
void Employee::setSalary(int sal){
  //salary = (sal >= 0) ? sal : 0;
  int (sal <= 0){
    salary = 0;
  }else{
    salary = sal;
  }
}


int Employee::giveRaise(){
  salary = salary * 1.25;
  return salary;}
