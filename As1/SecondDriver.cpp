//Hao Qi 40105579


#include "Employee.h"

#include <iostream>
#include <cstdlib>

using namespace std;

int compare(const void* a, const void* b){
	Employee* e1 = (Employee*) a;
	Employee* e2 = (Employee*) b;

	return (e1->getSalary() - e2->getSalary());
}

int testSortEmployeeSalary(){
    Employee e[] = {
        Employee("John", "smith", 3500),
        Employee("Julian", "Richman", 7000),
        Employee("Brack", "Obama", 4500),
        Employee("Bill", "Clinton", 8000),
        Employee("George", "Bush", 3000),
        Employee("Hao", "Qi", 9500),
        Employee("Mitch", "Mcconnel", 2000),
        Employee("Jimmy", "Carter", 7500),
        Employee("Ronald", "Regan", 6500),
        Employee("Sam", "Adam", 5500)
    };
    //count number of employee
    cout << "\n# of employee: " << Employee::count << endl;

    //size of employee array
    int size = sizeof(e)/sizeof(e[0]);

    //use qsort
    qsort(e,size,sizeof(Employee),compare);

    e[0].display();
    for(int i = 0; i < size; ++i){
    	e[i].displayEmployee();
    	//check if the current salary is bigger than the next one
    	if((e[i].getSalary() > e[i + 1].getSalary()) && i < (size - 1)){
    		//display error message and return false
    		cout << "Sort Failed" << endl;
        	return 1;
    	}
    }
	cout << "Sort Successfully!" << endl;
	cout << endl;
    return 0;

}

int main(){
	//create two employee objects
	Employee em1("Jon", "Stewart", 11000);
	Employee em2("Lisa", "Oliver", 7780);

	//display
	cout << "\nEmployee Info Before Raising Salary: " << endl;
	cout << endl;
	em1.display();
	em1.displayEmployee();
	em2.displayEmployee();

	//raise salary
	em1.raiseSalary(10);
	em2.raiseSalary(10);

	//display
	cout << "\nEmployee Info After Raising Salary: " << endl;
	cout << endl;
	em1.display();
	em1.displayEmployee();
	em2.displayEmployee();
	cout << endl;

	testSortEmployeeSalary();



	return 0;
}

