#include "Employee.h"

#include <iostream>
#include <iomanip>

using namespace std;

int Employee::count = 0;

//constructor
Employee::Employee(): firstname("NULL"), lastname("NULL"), salary(salary > 0 ? salary : 0) {
	cout << "Default Constructor Called!" << endl;
	++count;
}

Employee::Employee(const string& fn, const string& ln, int s)
: firstname(fn), lastname(ln), salary(s > 0 ? s : 0) {
	cout << "Constructor Called!" << endl;
	++count;
}

//copy constructor
Employee::Employee(const Employee& other) :
		firstname(other.firstname), lastname(other.lastname), salary(other.salary){
	cout << "Copy Constructor Successfully Called!" << endl;
	++count;
}

//display
void Employee::display() const{
	cout << left << setw(12) << "First Name"
			<< setw(12) << "Last Name"
			<< setw(15) << "Monthly Salary "
			<< setw(15) << "Yearly salary" << endl;
    cout << string(55, '-') << endl;
}

void Employee::displayEmployee() const{
	cout << left << setw(12) << firstname
				 << setw(12) << lastname
				 << setw(15) << salary
				 << setw(15) << Employee::getYearlySalary() << endl;
}



//destructor
Employee::~Employee(){
	cout << left << setw(13)<< "Employee object: " << setw(2) << firstname << ", "
			<< setw(5) << lastname << setw(5) << " successfully destructed!" << endl;
	--count;
	cout << "Employees Left: " << count << endl;
}

//getters
string Employee::getFirstName() const{
	return firstname;
}
string Employee::getLastName() const{
	return lastname;
}
int Employee::getSalary() const{
	return salary;
}
int Employee::getYearlySalary() const{
	return salary * 12;
}

//setters
void Employee::setFirstName(const string& fn){
	firstname = fn;
}
void Employee::setLastName(const string& ln){
	lastname = ln;
}
void Employee::setSalary(const int& s){
	salary = s;
}
void Employee::raiseSalary(double r) {
	salary +=  salary *  r / 100;
}

