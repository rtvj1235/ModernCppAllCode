#include "Vehicle.h"

Vehicle::Vehicle(std::string id, std::string brand, float price)
    :vehicleId(id),vehicleBrand(brand),vehiclePrice(price) {}

Vehicle::~Vehicle()
{
    std::cout<<"Vehicle with ID:"
            << this->vehicleId
            << this->vehiclePrice<<"\n";
}


