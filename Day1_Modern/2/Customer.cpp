#include "Customer.h"
#include "CustomerType.h"

Customer::Customer()
{
    customerId = 1;
    customerName = "Omkar Shirote";
    customerType = CustomerType::REGULAR;
    customerStoreCredit = 4324.01f;
    customerTransactionAmounts = {100.0f, 599.99f, 32.21f, 432.76f, 1000.54f};   
}

Customer::Customer(const Customer &obj)
{
    customerId = obj.customerId;
    customerName = obj.customerName;
    customerType = obj.customerType;
    customerStoreCredit = obj.customerStoreCredit;
    customerTransactionAmounts = obj.customerTransactionAmounts;
}

Customer::Customer(int id, std::string name, CustomerType type, TransactionContainer amountList, float storeCredit) 
    :customerId(id) ,customerName(name), customerType(type), customerTransactionAmounts(amountList), customerStoreCredit(storeCredit)
{

}

Customer* Customer::operator=(const Customer rhs)
{
    Customer *temp;
    temp->customerId = rhs.customerId;
    temp->customerName = rhs.customerName;
    temp->customerStoreCredit = rhs.customerStoreCredit;
    temp->customerTransactionAmounts = rhs.customerTransactionAmounts;
    temp->customerType = rhs.customerType;

    return temp;
}

int Customer::operator+(const Customer rhs)
{
    return this->customerStoreCredit + rhs.customerStoreCredit;
}

std::string Customer::getCustomerTypeString()
{   

    if(this->customerType == CustomerType::PREMIUM) return "Premium";
    else if(this->customerType == CustomerType::REGULAR) return "Regular";
    else return "VIP";

}

std::ostream &operator<<(std::ostream &os, const Customer &rhs) {
    os << "customerId: " << rhs.customerId<<"\n"
       << " customerName: " << rhs.customerName<<"\n"
       << " customerStoreCredit: " << rhs.customerStoreCredit<<"\n";
    return os;
}
