#include <iostream>
#include <memory>
#include <list>
#include "Customer.h"
#include "Functionalities.h"
#include "CustomerType.h"

using Pointer = std::shared_ptr<Customer>;
using Container = std::list<Pointer>;

int main(){

    Container data;

    // Function to create objects
    CreateObjects(data);

    std::cout<<"Customer with Highest Transaction Amount : ";
    std::cout<<customerIdWithHighestTransactionAmount(data);

    /*
        Same Type of Customer list
    */
    Container matcingTypeContainer;
    std::cout<<"\n\nCustmer with matcing types : ";
    matcingTypeContainer = FindMatcingTypeCustomer(data, CustomerType::REGULAR);
    for(auto& itr : matcingTypeContainer){
        displayInfo(itr);
    }


    /*
        Range of Customer Store credit is in between 100 and 200
    */
    Container matcingRangeContainer;
    std::cout<<"\n\nCustmer with matcing Ranges :";
    matcingRangeContainer = FindCustomerStoreCreditRange(data);
    for(auto& itr : matcingRangeContainer){
        std::cout<<*itr;
    }

    /*
        Function to find customer instace with lowest and highest customerStoreCredit
    */
    void CustomerWithLowestAndHighestCreditRange(Container& data);

    /*
        Function to find average of customer store credits of same customer type
    */
   std::cout<<"\n\nFind average of Customer Store Credit"<<FindMatcingTypeCustomerAverage(data, CustomerType::REGULAR);

    return 0;
}