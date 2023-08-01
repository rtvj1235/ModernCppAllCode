#include "Car.h"

std::string displayCarType(CarType type)
{
    if(type == CarType::HATCHBACK) return "HATCHBACL";
    else if(type == CarType::SEDAN) return "SEDAN";
    else{
        return "SPORTS";
    }
}

Car::Car(std::string vehicleId, int registrationyear,
    VehicleType vehicleType, Reference InsurancePlan,float price, CarType ctype, std::string colour)
    :   Vehicle(vehicleId,registrationyear,vehicleType,InsurancePlan),
    carPrice(price), carType(ctype), carColour(colour)
{}

Car::~Car()
{
    std::cout<<"CAR DESTROYED\n";
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " carPrice: " << rhs.carPrice
       << " carType: " << displayCarType(rhs.carType)
       << " carColour: " << rhs.carColour;
    return os;
}
