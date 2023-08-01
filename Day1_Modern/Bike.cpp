#include "Bike.h"

Bike::Bike(std::string id, std::string brand, float price, BikeType biket)
    : Vehicle(id,brand,price),btype(biket){}

float Bike::CalculateTax()
{
    return 0.05f * this->getVehiclePrice();
}

Bike::~Bike()
{
    std::cout<<"Bike with id:"
            << this->getVehicleId()
            <<"id destroyed"<<'\n';
}
