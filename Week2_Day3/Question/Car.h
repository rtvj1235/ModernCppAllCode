#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "CarType.h"
#include "Vehicle.h"

class Car:public Vehicle
{
private:
    /* data */
    float carPrice;
    CarType carType;
    std::string carColour;
public:
    Car(/* args */) = delete;
    Car(const Car& obj) = delete;
    Car(Car&& obj)= delete;
    Car(std::string vehicleId, int registrationyear,VehicleType vehicleType, Reference InsurancePlan,
        float price, CarType ctype, std::string colour);
    ~Car();

    float getCarPrice() const { return carPrice; }
    void setCarPrice(float carPrice_) { carPrice = carPrice_; }

    CarType getCarType() const { return carType; }
    void setCarType(const CarType &carType_) { carType = carType_; }

    std::string getCarColour() const { return carColour; }
    void setCarColour(const std::string &carColour_) { carColour = carColour_; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

};


std::string displayCarType(CarType type);

#endif // CAR_H
