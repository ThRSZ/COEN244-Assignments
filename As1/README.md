# COEN 244 Assignment

**Contributors**
 - Thomas Szaktilla (#40065829) - [ThRSZ](https://github.com/ThRSZ)
 - Hao Qi (#40105579) - [hisanip](https://github.com/hisanip)

## **Question**


```cpp

```

### - *Execution*

![Invoice-Terminal](https://github.com/ThRSZ/COEN244-Assignments/blob/main/Figures/Invoice-Terminal.png)

## **Question 3.11**

This question required a class titled `Employee`. The first 3 task had similar requirements to question 3.12 of public/private members, setters/getters, overloaded constructor/destructor.

The question also required a function to be invoked that raised the salary of a given employee. This was done using the following function:

```
void Employee::raiseSalary(double r) {
	salary +=  salary *  r / 100;
}
```

This function was then called in the SecondDriver.cpp file as followed:
```cpp
	Employee em1("Jon", "Stewart", 11000);
    //...
    //...
	//raise salary
	em1.raiseSalary(10);

```

The question required function which would sort employees' salary, invoking `qsort`. This was implemented in the following test, using a compare function: 

```cpp
int compare(const void* a, const void* b){
	Employee* e1 = (Employee*) a;
	Employee* e2 = (Employee*) b;

	return (e1->getSalary() - e2->getSalary());
}
```

```cpp
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
```
The function invokes `qsort` on an array of objects, then iterates through a for loop assesing whether the current index's salary is greater than the previous index and less than the next.

### - *Execution*

![Employee-Terminal1](https://github.com/ThRSZ/COEN244-Assignments/blob/main/Figures/Employee-Terminal1.png)

![Employee-Terminal2](https://github.com/ThRSZ/COEN244-Assignments/blob/main/Figures/Employee-Terminal2.png)

