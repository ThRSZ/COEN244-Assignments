#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>

using namespace std;

class Employee{
private:
	string firstname;
	string lastname;
	int salary;

public:
	static int count;

	//constructor
	Employee();
	Employee(const string& fName, const string& lName, int salary);
	Employee(const Employee& other);

	//destructor
	~Employee();

	//getters
	string getFirstName() const;
	string getLastName() const;
	int getSalary() const;
	int getYearlySalary() const;

	//setters
	void setFirstName(const string& fn);
	void setLastName(const string& ln);
	void setSalary(const int& s);
	void raiseSalary(double r);

	//display
	void display() const;
	void displayEmployee() const;


};

#endif /* EMPLOYEE_H_ */
