#include "Customer.h"

/*
    Default constructor to set some default values
*/
Customer::Customer()
{
    customerId = 1;
    customerName = "akshay";
    typeCustomer = CustomerType::REGULAR;
    customerStoreCredits = 100000.00f;
}

/*
    Parametrized constructor to construct a new customer by passing values for each data members
*/
Customer::Customer(int id, std::string name, CustomerType type, TransactionAMount trans, float customerCredits)
    : customerId(id), customerName(name), typeCustomer(type), transamount(trans),customerStoreCredits(customerCredits)
{
}

/*
    A parametrized constructor that can construct a new customer using just the id value
*/
Customer::Customer(int id)
    : customerId(id) {}


/*
    overloading = operator to copy of RHS object into LHS OBJECT
*/
void Customer::operator=(Customer &obj)
{
    this->customerId = obj.customerId;
    this->customerName = obj.customerName;
    this->customerStoreCredits = obj.customerStoreCredits;
    this->typeCustomer = obj.typeCustomer;
    this->transamount = obj.transamount;
}

/*
    overloading + operator to add the customerStoreCredits of 2 customer instances
*/
float Customer::operator+(Customer &obj)
{
    return this->customerStoreCredits + obj.customerStoreCredits;
}

/*
    returns the sum of transaction amounts;
*/


/*
    overloading << operator to display all the data members of customer
*/
std::ostream &operator<<(std::ostream &os, const Customer &rhs)
{
    os << "customerId: " << rhs.customerId
       << " customerName: " << rhs.customerName
       << " typeCustomer: " << displayCustomerType(rhs.getTypeCustomer());
       std::cout<< " customerTranscationAmount: " ;
       for(auto &it  : rhs.transamount){
        std::cout<< it <<" ";
       }
       std::cout<<" customerStoreCredits: " << rhs.customerStoreCredits;
    return os;
}



std::string displayCustomerType(CustomerType type)
{
    if( type == CustomerType::PREMIUM){
        return "PREMIUM";
    }
    else if( type == CustomerType ::REGULAR){
        return "REGULAR";
    }
    else{
        return "VIP";
    }
}

