 #include <iostream>
#include "Functionalities.h"
#include "Customer.h"
#include "CustomerType.h"

#include <thread>


int main(){
    Container data;
    std::thread t1(&CreateObjects,data);
    t1.join();
    int temp = FindCustomerId(data);
    std::cout<<temp<<"\n";
    float avg = AverageCustomerStoreCredtis(data);
    std::cout<<avg<<"\n";

}