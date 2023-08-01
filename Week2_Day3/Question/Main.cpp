#include <iostream>
#include "Functionalities.h"
#include<list>
#include <memory>
#include <thread>


int main(){
    Container data;
    InsuranceContainer Icontaier;
    // CreateObjects(data,Icontaier);
    // // Container* temp = FindCarColourByVehicleType(data,CarType::SEDAN);
    // for(auto & a : data){
    //     std::cout<<*a<<"\n";
    // }
    // std::cout<<'\n';
    // std::cout<<"----------------------------------------------------------------------------------\n";
    // Container temp = FindCarPriceMatchVehicleType(data, VehicleType::PRIVATE);
    // for(auto & a : temp){
    //     std::cout<<*a<<"\n";
    // }
    // std::cout<<'\n';
    // std::cout<<"-------------------------------------------------------------------\n";
    // Container temp2 = InsuranceAmountOverThreshold(data,1001.0f);
    // for(auto & a: temp2){
    //     std::cout<<*a<<"\n";
    // }
    // std::cout<<'\n';

    // Container data;
    auto f2 = [](){std::cout<<"lambda thread\n";};
    std::thread t1(&tempfunction);
    // std::thread t2(&f2);
    // t2.join();
    t1.join();


}