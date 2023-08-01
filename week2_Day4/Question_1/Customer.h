#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "CustomerType.h"

#include <list>

using TransactionAMount = std::list<float>;

class Customer
{
private:
    /* data */
    int customerId;
    std::string customerName;
    CustomerType  typeCustomer;
    TransactionAMount transamount;
    float customerStoreCredits;

public:
    Customer();
    Customer(int id, std::string name, CustomerType type , TransactionAMount amount, float customerCredits);
    explicit Customer(int id);
    Customer(const Customer& obj);
    Customer(Customer&& obj) = delete;
    void operator= (Customer& obj);
    float operator+(Customer & obj);
    
    ~Customer() {}

    int getCustomerId() const { return customerId; }
    void setCustomerId(int customerId_) { customerId = customerId_; }

    std::string getCustomerName() const { return customerName; }
    void setCustomerName(const std::string &customerName_) { customerName = customerName_; }

    CustomerType getTypeCustomer() const { return typeCustomer; }
    void setTypeCustomer(const CustomerType &typeCustomer_) { typeCustomer = typeCustomer_; }

    float getCustomerStoreCredits() const { return customerStoreCredits; }
    void setCustomerStoreCredits(float customerStoreCredits_) { customerStoreCredits = customerStoreCredits_; }

    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);
    
    TransactionAMount getTransamount() const { return transamount; }
    void setTransamount(const TransactionAMount &transamount_) { transamount = transamount_; }
};


std::string displayCustomerType(CustomerType type);



#endif // CUSTOMER_H
