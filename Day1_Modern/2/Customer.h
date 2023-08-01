#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <list>
#include "CustomerType.h"

using TransactionContainer = std::list<float>;

class Customer
{

private:
    int customerId;
    std::string customerName;
    CustomerType customerType;
    TransactionContainer customerTransactionAmounts;
    float customerStoreCredit;


public:

    //Default Constructor
    Customer();

    // Copy constructor
    Customer(const Customer& obj); 

    //disabled move constructor
    Customer(const Customer&& obj) = delete;

    // Parameterized Constructor
    Customer(int id, std::string name, CustomerType type, TransactionContainer amountList, float customerStoreCredit);

    //= operator overloaded to copy RHS to LHS object
    Customer* operator=(const Customer rhs);

    // + operator oveloading to add customer store credits of to Customer
    int  operator+(const Customer rhs);


    ~Customer() {}

    int getCustomerId() const { return customerId; }
    void setCustomerId(int customerId_) { customerId = customerId_; }

    std::string getCustomerName() const { return customerName; }
    void setCustomerName(const std::string &customerName_) { customerName = customerName_; }

    TransactionContainer getCustomerTransactionAmounts() const { return customerTransactionAmounts; }
    void setCustomerTransactionAmounts(const TransactionContainer &customerTransactionAmounts_) { customerTransactionAmounts = customerTransactionAmounts_; }

    float getCustomerStoreCredit() const { return customerStoreCredit; }
    void setCustomerStoreCredit(float customerStoreCredit_) { customerStoreCredit = customerStoreCredit_; }

    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);

    std::string getCustomerTypeString();

    CustomerType getCustomerType() const { return customerType; }
    void setCustomerType(const CustomerType &customerType_) { customerType = customerType_; }
};

#endif // CUSTOMER_H
