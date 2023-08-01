#include "Functionalities.h"

#include <iostream>

int main()
{
    Container data;
    CreateObjects(data);
    // displayContainer(data);
    // float temp = AveragePriceOfCars(data);
    // std::cout<<"Average Price:"<<temp<<"\n";
    // FindMaximumPrice(data);
    // displayContainer(data);
    // std::cout<<CheckAllVehicleType(data,carType::SEDAN)<<"\n";
    std::cout<<AveragePriceMatchCartype(data,carType ::SUV)<<"\n";
}