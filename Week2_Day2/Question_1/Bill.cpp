#include "Bill.h"


Bill::Bill(float amount, float tax, Reference associatedInvoice)
 : billAssociatedInvoice(associatedInvoice)
 {
    if(tax > amount){
        throw std::runtime_error("Tax cannot be more than amount");
    }
    this->billAmount = amount;
    this->billTaxAmount = tax;
 }

Bill::~Bill()
{
    std::cout<<"Destroyed Bill\n";
}

std::ostream &operator<<(std::ostream &os, const Bill &rhs) {
    os << "billAmount: " << rhs.billAmount
       << " billTaxAmount: " << rhs.billTaxAmount
       << " billAssociatedInvoice: " << (rhs.billAssociatedInvoice).get();
    return os;
}
