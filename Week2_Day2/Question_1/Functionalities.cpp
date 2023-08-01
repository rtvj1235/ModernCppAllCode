#include <iostream>
#include <list>
#include "Bill.h"
#include <memory>
#include <functional>
#include "Functionalities.h"

std::function<void(InvoiceContainer& Idata)> CreateInvoice = [](InvoiceContainer& Idata){
    Idata.emplace_back(std::make_shared<Invoice>("101IV",InvoiceType::E_BILL,1));
    Idata.emplace_back(std::make_shared<Invoice>("102IV",InvoiceType::PAPER_SLIP,2));
    Idata.emplace_back(std::make_shared<Invoice>("103IV",InvoiceType::SMS_GENRATED,3));
};


/*
    A LAMBDA FUNCTION TO CREATE AN OBJECT 
*/


std::function<void(Container & data,InvoiceContainer& lst)> CreateObjects = [](Container& data,InvoiceContainer& lst){

    CreateInvoice(lst);
    InvoiceContainer :: iterator it;
    it = lst.begin();

    data.emplace_back(std::make_shared<Bill>(
            133366667.0f,
            200.0f,
            std::ref(*it)
    ));
    *it++;
    data.emplace_back(
        std::make_shared<Bill>(
            67777.21f,
            43.1f,
            std::ref(*it)
        )
    );
    *it++;

    data.emplace_back(
        std::make_shared<Bill>(
            1213.0f,
            23.0f,
            std::ref(*it)
        )
    );


};

/*
    FindHighestBillAmountInvoiceNumber is an ally initialized stud function wrappe 
    to a function that takes one lvalue reference to a container and returns a stud string
*/
std::function<std::string(Container& data) > FindHighestBillAmountInvoiceNumber = [](Container& data){
    
    if(data.empty())
    {
        throw std::runtime_error("EMPTY");
    }
    float max = 0;
    std::string res = "";
    for(auto & a : data){
        if(a->getBillAmount() > max){
            max = a->getBillAmount();
            res = a->getBillAssociatedInvoice().get()->getInvoiceNumber();
        }
    }
    return res;

};


/*
    A lambda function to find and return the billAmount for an invoice instance whose
    invoiceNumber provided as an argument form a data container of biill instances.
*/
std::function<float(Container& data,std::string number)> BillAmountGivenBillNumber = 
    [](Container& data,std::string number){

    if(data.empty()){
        throw std::runtime_error("EMPTY");
    }

    for(auto & a : data){
        if(((a->getBillAssociatedInvoice().get())->getInvoiceNumber() == number )){
            return a->getBillAmount();
        }
    }
    throw std::runtime_error("NO MATCHING INVOICE NUMBER IS FOUND");
};

/*
    A lambda function to find and return billAssociatedInvoice instances ina container for all 
    Bill instances stored in a data container whose billAmount is over a threshold passed as an argument as
    well
*/
std::function<InvoiceContainer(Container& data, float threshold)> BillInvoiceAboveThreshold = 
    [](Container & data, float threshold){
        InvoiceContainer result;
        for(auto & a : data){
            if(a->getBillAmount() > threshold){
                result.emplace_back(a->getBillAssociatedInvoice().get());
            }
        }
        return result;
};


using Box  = std::reference_wrapper<int> ;

int main(){
    int n1 =10;
    int n2 = 20;
/*
    Demonstrate function
*/
// std::function<void()> DemonstrateFUnctionalities = [](){

// };


