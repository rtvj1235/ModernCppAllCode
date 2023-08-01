/*
    This flile declares Vehicle attributes including pure virtual function
*/
#include<iostream>
#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
private:
    std::string vehicleId;
    std::string vehicleBrand;
    float vehiclePrice;
public:

/*
    IF WE DONT WANT TO USE DEFAULT CONSTRUCTOR THEN USE DELETE KEYWORD LIKE THIS 
    IT WILL DISABLE DEFAULT CONSTRUCTOR
*/
    Vehicle() = delete; 
    Vehicle(std::string id, std::string brand, float price);

/*
    This is Default (enabled) copy constructor 
*/
    Vehicle(const Vehicle& obj) = default; 
    virtual float CalculateTax() = 0;        // PURE VIRTUAL 
    ~Vehicle();

    std::string getVehicleId() const { return vehicleId; }
    void setVehicleId(const std::string &vehicleId_) { vehicleId = vehicleId_; }

    std::string getVehicleBrand() const { return vehicleBrand; }
    void setVehicleBrand(const std::string &vehicleBrand_) { vehicleBrand = vehicleBrand_; }

    float getVehiclePrice() const { return vehiclePrice; }
    void setVehiclePrice(float vehiclePrice_) { vehiclePrice = vehiclePrice_; }


};


#endif // VEHICLE_H
