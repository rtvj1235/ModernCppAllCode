#include "Vehicle.h"



std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "vehicleId: " << rhs.vehicleId
       << " vehicleRegistrationyear: " << rhs.vehicleRegistrationyear
       << " vehicleType: " << displayVehicleType(rhs.vehicleType);
    //    << " vehicleInsurancePlan: " << rhs.vehicleInsurancePlan;
    return os;
}
std::string displayVehicleType(VehicleType type)
{
    if(type == VehicleType::COMMERCIAL) return "COMMERCIAL";
    else if(type == VehicleType::PRIVATE)
        return "PRIVATE";
    else{
        return "SPECIAL_PURPOSE";
    }
}

Vehicle::Vehicle(std::string vId, int registrationyear, VehicleType vehicleType_, Reference InsurancePlan)
    : vehicleId(vId),vehicleRegistrationyear(registrationyear), vehicleInsurancePlan(InsurancePlan),vehicleType(vehicleType_)
{
    
}

Vehicle::~Vehicle()
{
    std::cout<<"Vechicle Destroyed\n";
}
