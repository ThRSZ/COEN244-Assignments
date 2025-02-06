#include "Employee.h"

std::string printEmployees(){
  std::string testPrint = "";
  const int SIZE = 5;
  Employee employees[SIZE] = {
    Employee(),
    Employee("Biggie", "Smalls", 100),
    Employee("Lebron", "James", 500),
    Employee("Don", "Quixote", -5),
    Employee("Son", "Goku", 9001),
  };
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Employee #" << i + 1 << ":\n";
        std::cout << "  Name: " << employees[i].getFirstName() << " " << employees[i].getLastName() << "\n";
        std::cout << "  Salary: $" << employees[i].getSalary() << "\n\n";
    }
  return testPrint; 
}

std::string testRaise(){
  std::string null = "";
  Employee raiseEmployee("Biggie", "Smalls", 100);
  std::cout << raiseEmployee.getFirstName() << " " << raiseEmployee.getLastName() <<
  " received a 25% raise!" << std::endl;
  std::cout << "Their current salary is: $" << raiseEmployee.giveRaise() << std::endl;
  return null;
}

int main() {
 
  std::cout << printEmployees() << std::endl;
  std::cout << testRaise() << std::endl;

  return 0;
}


/*

g++ -c Employee.cpp
g++ -c mainEmployee.cpp
g++ -o Employee mainEmployee.o Employee.o

## Problem Statement ##

3.11 ( Employee Class) Create a class called Employee that includes three pieces of information as data members: first name (type string ),
a last name (type string ) and a monthly salary (type int ). Your class should have a constructor that initializes the three data members.
Provide a set and a get function for each data member. If the monthly salary is not positive, set it to 0 .
Write a test program that demonstrates class Employee ’s capabilities. Create two Employee objects and display each object’s yearly salary.
Then give each Employee a 10 percent raise and display each Employee ’s yearly salary again.

- [ ] Task 2.1 add the copy constructor of class Employee. (10 points)
- [ ] Task 2.2 add the destructor of class Employee. (10 points)
- [ ] Task 2.3 address the requirements in the 3.11 and Task 2.1 and 2.2. 
        The test program should follow the unit testing structure introduced at the lecture demos.
        (A reference example is on the “Summary and reference” web page on Moodle.) (20 points)

        Checking the “if the monthly salary is positive or not and setting the value to zero” can
        follow the example of class Time in the lecture demos.

void Time::setTime (int h, int m, int s){
  hour = (h >= 0 && h < 24) ? h : 0;
  minute = (m >= 0 && m < 60) ? m : 0;
  second = (s >= 0 && s < 60)? s : 0;
}//end function setTime

        Use member initialization list to program the constructor with three parameters.

- [ ] Task 2.4 Write a new test function called int testSortEmployeeSalary(). Create an array
        of Employee objects with minimal 10 objects with different salary values. This function
        sort the Employee objects in ascending order based on the salary value. The main()
        function should invoke testSortEmployeeSalary () in an assert form to print out if the
        test passes or fails. (20 points)
*/
