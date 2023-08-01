#ifndef BIKE_H
#define BIKE_H

#include<iostream>
#include"BikeCategories.h"
#include"Vehicle.h"


class Bike : public Vehicle{
private:
    BikeType btype;
public:

    Bike() =  delete;
    Bike(const Bike& obj) = default;
    Bike(std::string id, std::string brand, float price,BikeType biket);
    float CalculateTax() override;
    ~Bike();

    BikeType getBtype() const { return btype; }
    void setBtype(const BikeType &btype_) { btype = btype_; }
};
#endif // BIKE_H
