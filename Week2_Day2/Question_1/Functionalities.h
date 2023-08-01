#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <iostream>
#include <list>
#include "Bill.h"
#include <memory>
#include <functional>

using Pointer = std::shared_ptr<Bill>;
using Container = std::list<Pointer>;
using InvoiceContainer = std::list<std::shared_ptr<Invoice>>;

/*
    A LAMBDA FUNCTION TO CREATE AN OBJECT 
*/

/*
    Create object for INVOICE
*/
extern std::function<void(InvoiceContainer& Idata)> CreateInvoice;


extern std::function<void(Container & data,InvoiceContainer& lst)> CreateObjects;

/*
    FindHighestBillAmountInvoiceNumber is an externally initialized stud function wrapper
    to a function that takes one lvalue reference to a container and returns a stud string
*/
extern std::function<std::string(Container& data) > FindHighestBillAmountInvoiceNumber;

/*
    A lambda function to find and return the billAmount for an invoice instance whose
    invoiceNumber provided as an argument form a data container of biill instances.
*/
extern std::function<float(Container& data,std::string number)> BillAmountGivenBillNumber;

/*
    A lambda function to find and return billAssociatedInvoice instances ina container for all 
    Bill instances stored in a data container whose billAmount is over a threshold passed as an argument as
    well
*/
extern std::function<InvoiceContainer(Container& data, float threshold)> BillInvoiceAboveThreshold;

/*
    Demonstrate function
*/
// extern std::function<void()> DemonstrateFUnctionalities;

#endif // FUNCTIONALITIES_H
