#include <iostream>
#include "Functionalities.h"
#include "Bill.h"
#include "Invoice.h"

int main(){
    Container data;
    InvoiceContainer lst;
    CreateObjects(data,lst);
    // std::cout<<BillAmountGivenBillNumber(data,"102IV")<<"\n";
    // std::cout<<FindHighestBillAmountInvoiceNumber(data)<<"\n";
    InvoiceContainer res = BillInvoiceAboveThreshold(data,1);
    for(auto & a : res){
        std::cout<<*a<<"\n";
    }
}