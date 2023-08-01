#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <iostream>
#include <memory>
#include "Customer.h"
#include <list>

using Pointer = std::shared_ptr<Customer>;
using Container = std::list<Pointer>;

/*
    Function to create objects
*/
void CreateObjects(Container& data);
/*
    Functio which finds combined customerId of customer with highest customer transation amount;
*/
int customerIdWithHighestTransactionAmount(Container& data);


/*
    Function to find matching type customer for user
*/
Container FindMatcingTypeCustomer(Container& data, CustomerType type);


/*
    Finction to find Customer Store Credit Range between 100-200
*/
Container FindCustomerStoreCreditRange(Container& data);

/*
    Function to find customer instace with lowest and highest customerStoreCredit
*/
void CustomerWithLowestAndHighestCreditRange(Container& data);

float FindMatcingTypeCustomerAverage(Container &data, CustomerType type);

void displayInfo(Pointer c);

#endif // FUNCTIONALITIES_H
