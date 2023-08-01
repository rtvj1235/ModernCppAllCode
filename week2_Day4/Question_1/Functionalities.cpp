#include "Functionalities.h"
#include <memory>
#include <list>
/*
    A function to create objects
*/
void CreateObjects(Container &data)
{

    data.emplace_back(std::make_unique<Customer>(1,"akshay",CustomerType::PREMIUM,std::list<float>{1.0,2.0,3.0,4.0,5.0},1234.00f));
    data.emplace_back(std::make_unique<Customer>(2,"rohan",CustomerType::PREMIUM,std::list<float>{1989,200.0,300.0,400.0,500.0},1234.00f));
    data.emplace_back(std::make_unique<Customer>(3,"mihir",CustomerType::PREMIUM,std::list<float>{100.0,200.0,300.0,400.0,500.0},1234.00f));
    data.emplace_back(std::make_unique<Customer>(4,"aslam",CustomerType::PREMIUM,std::list<float>{1.0,2.0,3.0,4.0,5.0},1234.00f));


}

/*
    A FUNCTION TO FIND THE CUSTOMERID OF THE COUSTOMER WHOSE COMBINED VALUES customerTransactionAMounts value is the
    highest
*/

int FindCustomerId(Container &data)
{
    int temp;
    float max = 0;
    for(auto &itr : data){
        int sum = 0;
        for(auto amount  : itr->getTransamount()){
            sum+=amount;
        }
        if(sum > max){
            max = sum;
            temp = itr->getCustomerId();
        }
    }
    return temp;
}

/*
    A FUNCTION TO FIND AND RETURN A CONTAINER OF CUSTOMER OBJECT WHOSE CUSTOMERTYPE MATCHES
    THE TYPE PASSED AS THE SECOND ARGUMEMT
*/

Container FindObjectByCustomerType(Container &data, CustomerType type)
{
    Container temp;
    for (Pointer &a : data)
    {
        if (a->getTypeCustomer() == type)
        {
            temp.emplace_back(std::move(a));
        }
    }
    return temp;
}

/*
    A FUCNTION TO RETURN A CONTAINER OF ALL CUSTOMER INSTRANCE WHOSE CUSTOMERSTORECREDTIS are between 100
     and 200
*/

Container CustomerStoreCreditsBetweenValues(Container &data)
{
    Container temp;
    for (Pointer &a : data)
    {
        if ((a->getCustomerStoreCredits() >= 100 && a->getCustomerStoreCredits() <= 200))
        {
            temp.emplace_back(std::move(a));
        }
    }
    return temp;
}

/*
    A customer to find the customer instances with the lowest and highest customerStoreCredits and
    print th combined value for these credtis
*/
void LowestHighestCustomerStoreCredtis(Container &data)
{
    Container ::iterator it;
    float max = 0;
    float temp = (*(*data.begin())).getCustomerStoreCredits();
    for (Pointer &a : data)
    {
        if (a->getCustomerStoreCredits() > max)
        {
            max = a->getCustomerStoreCredits();
        }
        else if (a->getCustomerStoreCredits() < temp)
        {
            temp = a->getCustomerStoreCredits();
        }
    }
    std::cout << "Combined values :" << max + temp << "\n";
}

/*
    A Function to find the average customerStoreCredits of all customer whose customer type
    matches the type provided as the second argument
*/

float AverageCustomerStoreCredtis(Container &data)
{
    float sum = 0.0f;
    int N = 0;
    for (Pointer &a : data)
    {
        sum += a->getCustomerStoreCredits();
        N++;
    }
    return sum / N;
}

/*
    A function of find if all customer instances in a container are of the customer type
    passed as the second arguments
*/

bool FindCustomerTypeIsSame(Container &data, CustomerType type)
{
    bool flag = true;
    for (Pointer &a : data)
    {
        if (a->getTypeCustomer() == type)
            flag = true;
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
        return true;
    else
        return false;
}


