#ifndef INVOICE_H
#define INVOICE_H
#include <string>

class Invoice {
  public:

    Invoice(); //Default Constructor
    Invoice(const std::string &partNumber,
            const std::string &partDescription, 
            int quantity, int price); //constructor
  
    Invoice(const Invoice &other);
    ~Invoice();
    
    std::string getPartNumber() const;
    void setPartNumber(const std::string &pNumber); //Pass variable of namesake

    std::string getPartDescription() const;
    void setPartDescription(const std::string &pDesc); //Pass variable of namesake

    int getQuantity() const;
    void setQuantity(int q); //Pass variable of namesake

    int getPrice() const;
    void setPrice(int p); //Pass variable of namesake

    int getInvoiceAmount() const;

    Invoice clone() const;
    Invoice clone(const Invoice &other) const;  
    
  private:
    std::string partNumber;
    std::string partDescription;
    int quantity;
    int price;

};

#endif
