#include "Car.h"

Car::Car(std::string id, float price, std::string carBrand, int carSeatCount, carType carCategory)
    : Vehicle(id, price)
{
    this->carBrand = carBrand;
    this->carCategory = carCategory;
    this->carSeatCount = carSeatCount;
}

Car::~Car()
{
    std::cout << "Car Destroyed"
              << "\n";
}

std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << static_cast<const Vehicle &>(rhs)
       << " carBrand: " << rhs.carBrand
       << " carSeatCount: " << rhs.carSeatCount
       << " carCategory: " << displayCarType(rhs.carCategory);
    return os;
}

std::string displayCarType(carType type)
{
    if (type == carType::HYBRID)
    {
        return "HYBRID";
    }
    else if (type == carType ::SEDAN)
        return "SEDAN";
    else
        return "SUV";
}
