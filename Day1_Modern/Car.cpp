
#include<iostream>
#include "Car.h"
#include"CarCategories.h"

Car::Car(std::string id, std::string brand, float price, std::string model, enum class carType ctype)
: Vehicle(id,brand,price) , carModel(model), car_type(ctype){}


Car::~Car()
{
    std::cout<< "Car with vehicle Id:"
            << this->getVehicleId()
            << "is destroyed"<<"\n";
}

float Car::CalculateTax()
{
    return 0.1f * this->getVehiclePrice();
}




