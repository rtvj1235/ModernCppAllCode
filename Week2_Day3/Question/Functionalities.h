#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Vehicle.h"
#include "Car.h"
#include "Insurance.h"
#include <memory>
#include <list>
#include <functional>

using Pointer = std::shared_ptr<Vehicle>;
using Container = std::list<Pointer>;
using InsuranceContainer = std::list<std::shared_ptr<Insurance>>;

using colourContainer = std::list<std::string>;

/*
    A FUNCTION THAT RETURNS THE LIST OF CAR INSTANCES WHOSE INSURANCE AMOUNT IS OVER
     A THRESHOLD PROVIDED AS AN INPUT CONSIDER THE SCENARIO OF NO CARS BEING ABOVE THE INSURANCE
     AMOUNT THRESHOLD
*/

extern std::function<void(InsuranceContainer &data)> CreateInsurance;
extern std::function<void(Container &data, InsuranceContainer &Icontaier)> CreateObjects;

extern std::function<Container(Container &data, float threshold)> InsuranceAmountOverThreshold;

/*
    A FUNCTION THAT RETURN CARPRICE OF ALL CARS WHOSE VEHICLE TYPE MATCHES THE
    TYPE PASSED AS AN ARGUMENT
*/

extern std::function<Container(Container &data, VehicleType type)> FindCarPriceMatchVehicleType;

/*
    A FUNCTION THAT RETURN A CAR COLOUR IN A CONTAINER FOR ALL CAR UNITS
    WHOSE VEHICLE TYPE IS PRIVATE
*/

extern std::function<colourContainer(Container &data, VehicleType type)> FindCarColourByVehicleType;

extern std::function<float(Container &data)> FindAverage;


void tempfunction();

#endif // FUNCTIONALITIES_H
