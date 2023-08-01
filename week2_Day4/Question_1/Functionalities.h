#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include "Customer.h"
#include "CustomerType.h"
#include <list>
#include <memory>

using Pointer = std::unique_ptr<Customer>;

using Container = std::list<Pointer>;


/*
    A FUNCTION TO CREATE OBJECTS
*/

void CreateObjects(Container& data);


/*
    A FUNCTION TO FIND THE CUSTOMERID OF THE COUSTOMER WHOSE COMBINED VALUES customerTransactionAMounts value is the 
    highest
*/
int FindCustomerId(Container & data);

/*
    A FUNCTION TO FIND AND RETURN A CONTAINER OF CUSTOMER OBJECT WHOSE CUSTOMERTYPE MATCHES
    THE TYPE PASSED AS THE SECOND ARGUMEMT
*/

Container FindObjectByCustomerType(Container & data, CustomerType  type);

/*
    A FUCNTION TO RETURN A CONTAINER OF ALL CUSTOMER INSTRANCE WHOSE CUSTOMERSTORECREDTIS are between 100
     and 200 
*/

Container CustomerStoreCreditsBetweenValues(Container & data);

/*
    A customer to find the customer instances with the lowest and highest customerStoreCredits and 
    print th combined value for these credtis 
*/

void LowestHighestCustomerStoreCredtis(Container & data);


/*
    A Function to find the average customerStoreCredits of all customer whose customer type
    matches the type provided as the second argument
*/

float AverageCustomerStoreCredtis(Container & data);

/*
    A function of find if all customer instances in a container are of the customer type 
    passed as the second arguments
*/

bool FindCustomerTypeIsSame(Container & data, CustomerType type);


/*
    sum of all the cutomerTransaction amount 
*/


#endif // FUNCTIONALITIES_H
