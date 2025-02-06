#include <iostream>
#include "Invoice.h"

//Static Member Variables


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

//Getter & Setters
std::string Invoice::getPartNumber() const {return partNumber;}
void Invoice::setPartNumber(const std::string &pNumber){
  partNumber = pNumber;
}

std::string Invoice::getPartDescription() const {return partDescription;}
void Invoice::setPartDescription(const std::string &pDesc){
  partDescription = pDesc;}

int Invoice::getQuantity() const {return quantity;}
void Invoice::setQuantity(int q){
  if (q < 0){
    quantity = 0;
  } else{
    quantity = q;
  }
}

int Invoice::getPrice() const {return price;}
void Invoice::setPrice(int p){
  if (p < 0){
    price = 0;
  }else{
    price = p;
  };}

int Invoice::getInvoiceAmount() const{
  return price * quantity;
}

Invoice Invoice::clone() const {
  return Invoice(partNumber, 
                 partDescription, 
                 quantity, 
                 price);
}

Invoice Invoice::clone(const Invoice &other) const{
  return Invoice(other.partNumber, 
                 other.partDescription, 
                 other.quantity, 
                 other.price);
}

