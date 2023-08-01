#include"Invoice.h"
#include "InvoiceType.h"
#include <iostream>


std::ostream &operator<<(std::ostream &os, const Invoice &rhs) {
    os << "invoiceNumber: " << rhs.invoiceNumber
       << " invoiceType: " << DisplayEnum(rhs.invoiceType)
       << " invoiceItems: " << rhs.invoiceItems;
    return os;
}

std::string DisplayEnum(InvoiceType type)
{
    if(type == InvoiceType ::E_BILL) return "E_BILL";
    else if(type == InvoiceType::PAPER_SLIP)
        return "PAPER_SLIP";
    else{
        return "SMS_GENRATED";
    }
}

Invoice::Invoice(std::string number, InvoiceType type, int items)
    : invoiceNumber(number) , invoiceType(type), invoiceItems(items)
{}

Invoice::~Invoice()
{
    std::cout<<"Invoice Object Destroyed\n";
}
