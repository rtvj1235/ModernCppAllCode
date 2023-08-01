#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "carTypes.h"
#include <ostream>

class Car : public Vehicle
{
    std::string carBrand;
    int carSeatCount;
    carType carCategory;

public:
    Car() = delete;
    Car(std::string id, float price, std::string carBrand, int carSearCount, carType carCategory);
    Car(const Car &obj) = delete;
    Car(Car &&obj) = delete;
    ~Car();

    std::string getCarBrand() const { return carBrand; }
    void setCarBrand(const std::string &carBrand_) { carBrand = carBrand_; }

    int getCarSeatCount() const { return carSeatCount; }
    void setCarSeatCount(int carSeatCount_) { carSeatCount = carSeatCount_; }

    carType getCarCategory() const { return carCategory; }
    void setCarCategory(const carType &carCategory_) { carCategory = carCategory_; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

std::string displayCarType(carType type);

#endif // CAR_H
