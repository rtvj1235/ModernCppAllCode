#include "Functionalities.h"
#include <iostream>
#include <memory>
#include "Customer.h"
#include <list>

using Pointer = std::shared_ptr<Customer>;
using Container = std::list<Pointer>;


bool isEmpty(Container& data){

        return data.empty();
        
}

void CreateObjects(Container &data)
{
    data.emplace_back(new Customer(103, "Shreyas", CustomerType::REGULAR ,{11.1f, 88.23f}, 70.0f));
    data.emplace_back(new Customer(106, "Omkar", CustomerType::REGULAR ,{110.1f, 188.23f}, 101.0f));
    data.emplace_back(new Customer(108, "Shardul", CustomerType::VIP ,{10.1f, 118.23f}, 129.0f));
}

int customerIdWithHighestTransactionAmount(Container &data)
{
    
    if(isEmpty(data)){
        throw "Container is Empty";
    }

    int max_amt = 0;
    int id;

    for(auto& itr : data){
        int sum = 0;
        for(auto customer_amt : itr->getCustomerTransactionAmounts()){
            sum += customer_amt;
        }
        if(sum > max_amt){
            max_amt = sum;
            id = itr->getCustomerId();
        }
    }
    return id;
}



Container FindMatcingTypeCustomer(Container &data, CustomerType type)
{

    if(isEmpty(data)){
        throw "Container is Empty";
    }

    using SameCustomerTypeContainer = std::list<Pointer>;  
    SameCustomerTypeContainer sameCustomerTypeContainer; 

    Customer temp;
    for(auto& itr : data){
        if(itr->getCustomerType() == type){
            sameCustomerTypeContainer.emplace_back(itr);
        }
    }

    if(sameCustomerTypeContainer.empty()){
        throw "No matching customers";
    }

    return sameCustomerTypeContainer;
}



Container FindCustomerStoreCreditRange(Container &data)
{

    if(isEmpty(data)){
        throw "Container is Empty";
    }


    using RangeCustomerStoreCredit = std::list<Pointer>;  
    RangeCustomerStoreCredit rangeCustomerStoreCredit; 

    for(auto& itr : data){
        if(itr->getCustomerStoreCredit() >= 100 && itr->getCustomerStoreCredit()<=200){
            rangeCustomerStoreCredit.emplace_back(itr);
        }
    }

    return rangeCustomerStoreCredit;
}

void CustomerWithLowestAndHighestCreditRange(Container &data)
{

    if(isEmpty(data)){
        throw "Container is Empty";
    }
    
    Pointer temp1;
    Pointer temp2;

    int min = 0;
    int max = 0;

    for(auto& itr : data){
        if(min > itr->getCustomerStoreCredit()){
            min = itr->getCustomerStoreCredit();
            temp1 = std::move(itr);
        }
        if(max < itr->getCustomerStoreCredit()){
            max = itr->getCustomerStoreCredit();
            temp2 = std::move(itr);
        }
    }

    float sum = min + max;
    std::cout<<"Sum of highest and lowest customer creadit score is  "<< sum << std::endl;

    std::cout<<"Customer with Lowest and Highest Store Credit is ";
    displayInfo(temp1);
    std::cout<< "\n and \n";
    displayInfo(temp2);
    std::cout<<std::endl;

}


float FindMatcingTypeCustomerAverage(Container &data, CustomerType type)
{

    if(isEmpty(data)){
        throw "Container is Empty";
    }

    float sum = 0.0f;
    int count = 0;

    for(auto& itr : data){
        if(itr->getCustomerType() == type){
            sum += itr->getCustomerStoreCredit();
            count++;
        }
    }

     if(count == 0){
        throw "No matching customers";
    }

    return sum/count;
}

void displayInfo(Pointer c)
{


    std::cout<<"\nCustomer ID : "<< c->getCustomerId();
    std::cout<<"\nCustomer Name : "<< c->getCustomerName();
    std::cout<<"\nCustomer Type : "<< c->getCustomerTypeString();
    std::cout<<"\nCustomer Store Credit"<< c->getCustomerStoreCredit();
}
