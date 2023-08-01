#ifndef CAR_H
#define CAR_H

#include<iostream>
#include "CarCategories.h"

#include "Vehicle.h"
class Car : public Vehicle

{
private:
    std::string carModel;
    carType car_type;
public:
    Car() =  delete;
    Car(const Car& obj) = delete;
    Car(std::string id, std::string brand, float price,std::string model, carType ctype);
    ~Car();
    float CalculateTax();

    std::string getCarModel() const { return carModel; }
    void setCarModel(const std::string &carModel_) { carModel = carModel_; }

    // carType carType() const { return car_type; }
    // void setCarType(const carType &carType) { car_type = carType; }

    carType carType() const { return car_type; }
    void setCarType(const enum class carType &carType) { car_type = carType; }
};

#endif // CAR_H

