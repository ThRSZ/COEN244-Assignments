#include <iostream>
#include "Invoice.h"

std::string printInvoice(){
  std::string testPrint = "";
  const int SIZE = 5;
  Invoice accounts[SIZE] = {
    Invoice(),
    Invoice("D100", "Drill", 2, 80.00),
    Invoice("S101", "Screwdriver", 10, 5.00),
    Invoice("L105", "Level", 5, 15.00),
    Invoice("L106", "Ladder", 1, 50.00),
  };
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "invoice " << i + 1 << ":\n";
        std::cout << "  Number: " << accounts[i].getPartNumber() << "\n";
        std::cout << "  Description:  " << accounts[i].getPartDescription() << "\n";
        std::cout << "  Quantity: " << accounts[i].getQuantity() << "\n";
        std::cout << "  Price: " << accounts[i].getPrice() << "\n";
        std::cout << " Cost: " << accounts[i].getInvoiceAmount() << "$\n\n";
    }
  return testPrint; 
}

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

bool invoiceAmountTest(){

  const int SIZE = 5;
  Invoice accounts[SIZE] = {
    Invoice(),
    Invoice("D100", "Drill", 2, 80.00),
    Invoice("S101", "Screwdriver", 10, 5.00),
    Invoice("L105", "Level", 5, 15.00),
    Invoice("L106", "Ladder", 1, 50.00),
  };
  
  for (int i = 0; i < SIZE; ++i) {
    if(accounts[i].getQuantity() * accounts[i].getPrice() != accounts[i].getInvoiceAmount()){
        return false;
      }  
    }
  return true;
}


int main() { 
  
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

  result = invoiceCopyConstructorTest();
  testCount++;
  if (result) {
    passCount++;
    //std::cout << 
  }else {++failCount;}
  message = result? "passes!":"fails!";
  //assertion form for calling the unit testing function;
  std::cout << "The test for copy constructor " << message << std::endl;
  
  result = invoiceCloneTest();
  testCount++;
  if (result) {
    passCount++;
    //std::cout << 
  }else {++failCount;}
  message = result? "passes!":"fails!";
  //assertion form for calling the unit testing function;
  std::cout << "The test for clone function " << message << "\n\n";





  std::cout << passCount << " / " << testCount << " passes." << std::endl;
  std::cout << failCount << " / " << testCount << " fails." << std::endl;
  //invoiceCloneTest();


  return 0;
}
/*

g++ -c Invoice.cpp
g++ -c mainInvoice.cpp
g++ -o Invoice mainInvoice.o Invoice.o

## PROBLEM STATEMENT ##

3.10 ( Invoice Class) Create a class called Invoice that a hardware store might use to represent
an invoice for an item sold at the store. An Invoice should include four data members as part number
(type string ), a part description (type string ), a quantity of the item being purchased (type int ) and a price
per item (type int ). Your class should have a constructor that initializes the four data members.
Provide a set and a get function for each data member. In addition, provide a member function named getInvoiceAmount 
that calculates the invoice amount (i.e., multiplies the quantity by the price per item), then returns the amount as an int value.
If the quantity is not positive, it should be set to 0 . If the price per item is not positive, it should be set to 0 .
Write a test program that demonstrates class Invoice ’s capabilities.

- [x] Task 1.1 address the requirements in above problem statement. The test program
          should ollow the unit testing structure introduced at the lecture demos. (A reference
          example is on the “Summary and reference” web page on Moodle.) (20 points)
          Incrementally, we develop the Invoice class with the following extra specification.
- [x] Task 1.2 add the copy constructor of class Invoice. (5 points)
           Format: ClassName(const Classname &other);
- [x] Task 1.3 add the destructor of class Invoice. (5 points)
- [x] Task 1.4 define a public member function called clone() that returns an Invoice object
          with the identical values of the current Invoice object. (5 points)
- [x] Task 1.5 define a public member function with overloaded form of clone (const Invoice &) that returns an Invoice
          object with the identical values of the pass-by-reference Invoice object. (5 points)
- [x] Task 1.6 write a test program to demonstrates class Invoice’s capabilities defined in Task 1.2 – 1.5.
          The test program should follow the unit testing structure introduced at the lecture demos.
          (A reference example is on the “Summary and reference” web page on Moodle.) (10 points)

          The main() function should follow the assertion format to print out “pass” or “fail” for
          each unit test. For example,

//unit testing
std::string message = testArrayAccess()? "passes!":"fails!";
//assertion form for calling the unit testing function;
std::cout << "The case for array access" << message << std::endl;

          Finally, it should print out a statistics as “ m / n pass and k / n fail ” given the runtime
          unit test output, where m is the number of pass cases and k is the number of fail cases,
          and n is the number of total unit testing cases.
          For example, if 5 total number of test cases are invoked in the main() and 5 cases
          pass. The program should print out “5/5 pass and 0/5 fail”.


  Invoice Bill1;
  Invoice Bill2("D100", "Drill", 5, 10);
  
    std::cout << "Default Constructor:\n";
    std::cout << "Part Number: "      << Bill1.getPartNumber() << "\n"
              << "Part Description: " << Bill1.getPartDescription() << "\n"
              << "Quantity: "         << Bill1.getQuantity() << "\n"
              << "Price: "            << Bill1.getPrice() << "\n"
              << "Invoice Amount: "   << Bill1.getInvoiceAmount() << "\n\n";

    std::cout << "Overloaded Constructor:\n";
    std::cout << "Part Number: "      << Bill2.getPartNumber() << "\n"
              << "Part Description: " << Bill2.getPartDescription() << "\n"
              << "Quantity: "         << Bill2.getQuantity() << "\n"
              << "Price: "            << Bill2.getPrice() << "\n"
              << "Invoice Amount: "   << Bill2.getInvoiceAmount() << "\n\n";

    Invoice Bill3 = Bill2;

    std::cout << "Copy of Invoice:\n";
    std::cout << " Part Number: "      << Bill3.getPartNumber() << "\n"
              << " Part Description: " << Bill3.getPartDescription() << "\n"
              << " Quantity: "         << Bill3.getQuantity() << "\n"
              << " Price: "            << Bill3.getPrice() << "\n"
              << " Invoice Amount: "   << Bill3.getInvoiceAmount() << "\n\n";


*/
