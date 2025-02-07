# COEN 244 Assignment

**Contributors**
 - Thomas Szaktilla (#40065829) - [ThRSZ](https://github.com/ThRSZ)
 - Hao Qi (#40105579) - [hisanip](https://github.com/hisanip)

## **Question 3.10**

This question required the construction of a class `Invoice`, in which multiple data members where designated as private with getters and setters defined as public. The data members were defined as following in the .h file:

```cpp
class Invoice {
  public:

    // refer to code to see all data members and functions
    
  private:
    std::string partNumber;
    std::string partDescription;
    int quantity;
    int price;

};

```

The getters and setters were defined as following in the `Invoice.cpp` file, where the get function returned the data member and the setter passed a pointer to that data member:
```
std::string Invoice::getPartNumber() const {return partNumber;}
void Invoice::setPartNumber(const std::string &pNumber){
  partNumber = pNumber;
}
```

The default/overloaded/copy constructor and destructor are called in the following way:

```cpp
//Default Constructor
Invoice::Invoice() : partNumber(""), partDescription(""), quantity(0), price(0) {}

//Constructor
Invoice::Invoice(const std::string &pNumber, const std::string &pDesc,
                 int q, int p):
  partNumber(pNumber),
  partDescription(pDesc),
  quantity(q),
  price(p) {}

//Copy Constructor
Invoice::Invoice(const Invoice &other) : 
  partNumber(other.partNumber), 
  partDescription(other.partDescription),
  quantity(other.quantity),
  price(other.price){
  //std::cout << "Copy of Invoice was made.\n" << std::endl;
}


//Destructor
Invoice::~Invoice(){
  //std::cout << "Invoice has been deleted\n" << std::endl;
}
```
- **Note:** The text declaring the Invoice was destroid was commented out to clarity of terminal display. 

The following tests were made in the `mainInvoice.cpp` file to test the efficacy of certain functions, namely the clone function, the copy constructor and the `getInvoiceAmount()` function. Each test wast defined as a `bool` value as a simple means of return a basic `true` or `false` conclusion to the respective test. 

```cpp
bool invoiceCloneTest(){

  const int SIZE = 5;
  Invoice accounts[SIZE] = {
    Invoice(),
    Invoice("D100", "Drill", 2, 80.00),
    Invoice("S101", "Screwdriver", 10, 5.00),
    Invoice("L105", "Level", 5, 15.00),
    Invoice("L106", "Ladder", 1, 50.00),
  };
  
  for (int i = 0; i < SIZE; ++i) {
    Invoice clonedInvoice = accounts[i].clone();
    if(
      clonedInvoice.getPartNumber() != accounts[i].getPartNumber() ||
      clonedInvoice.getPartDescription() != accounts[i].getPartDescription() ||
      clonedInvoice.getQuantity() != accounts[i].getQuantity() ||
      clonedInvoice.getPrice() != accounts[i].getPrice()){
        return false;
      }  
    }
  return true;
}
```

```cpp
bool invoiceCopyConstructorTest(){

    Invoice Bill1("C102", "Saw", 1, 100);
    Invoice copiedInvoice(Bill1);
    if(
      copiedInvoice.getPartNumber() != Bill1.getPartNumber() ||
      copiedInvoice.getPartDescription() != Bill1.getPartDescription() ||
      copiedInvoice.getQuantity() != Bill1.getQuantity() ||
      copiedInvoice.getPrice() != Bill1.getPrice()){
        return false;
      }  
  return true;
}
```

```cpp
bool invoiceAmountTest(){

    // Same Object Array as invoiceCloneTest
  
  for (int i = 0; i < SIZE; ++i) {
    if(accounts[i].getQuantity() * accounts[i].getPrice() != accounts[i].getInvoiceAmount()){
        return false;
      }  
    }
  return true;
}

```
Within the `main()` function three data members of type `int` were defined to keep track of the number of tests called, as well as the passes/fails. Another data member of type `bool` titled `result` was used to store the result of the respective called test. After each test the `testCount` variable was incremented and `passCount` or `failCount` depending on the the return value of `result`. Lastly a `string` titled `message` is assigned "passes!" or "fails!" given the value of `result`.

```cpp
  int testCount = 0;
  int failCount = 0;
  int passCount = 0;
  
  std::cout << printInvoice() << std::endl;

  bool result = invoiceAmountTest();
  testCount++;
  if (result) {
    passCount++;
    //std::cout << 
  }else {++failCount;}
  std::string message = result? "passes!":"fails!";
  //assertion form for calling the unit testing function;
  std::cout << "The test for Invoice Amount " << message << std::endl;

    // Repeated for every subsequent test


  std::cout << passCount << " / " << testCount << " passes." << std::endl;
  std::cout << failCount << " / " << testCount << " fails." << std::endl;
```
This allows the passCount/failCount to iterate based on the result of the given test and return the result to the display.


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

