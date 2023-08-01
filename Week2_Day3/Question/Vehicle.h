#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "VehicleType.h"
#include <functional>
#include "Insurance.h"
#include <memory>

using Reference = std::reference_wrapper<std::shared_ptr<Insurance>> ;

class Vehicle
{
private:
    /* data */
    std::string vehicleId;
    int vehicleRegistrationyear;
    VehicleType vehicleType;
    Reference vehicleInsurancePlan;

public:
    Vehicle(/* args */) = delete;
    Vehicle(const Vehicle& obj) = delete;
    Vehicle(const Vehicle&& obj)= delete;
    Vehicle(std::string vehicleId, int registrationyear,VehicleType vehicleType, Reference InsurancePlan);
    virtual ~Vehicle();

    std::string getVehicleId() const { return vehicleId; }
    void setVehicleId(const std::string &vehicleId_) { vehicleId = vehicleId_; }

    int getVehicleRegistrationyear() const { return vehicleRegistrationyear; }
    void setVehicleRegistrationyear(int vehicleRegistrationyear_) { vehicleRegistrationyear = vehicleRegistrationyear_; }

    VehicleType getVehicleType() const { return vehicleType; }
    void setVehicleType(const VehicleType &vehicleType_) { vehicleType = vehicleType_; }

    Reference getVehicleInsurancePlan() const { return vehicleInsurancePlan; }
    void setVehicleInsurancePlan(const Reference &vehicleInsurancePlan_) { vehicleInsurancePlan = vehicleInsurancePlan_; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

std::string displayVehicleType(VehicleType type);

#endif // VEHICLE_H
