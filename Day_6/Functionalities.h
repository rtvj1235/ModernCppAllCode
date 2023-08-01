#include "Car.h"
#include "Vehicle.h"
#include "carTypes.h"
#include <memory>
#include <list>

using Pointer = std::unique_ptr<Vehicle>;
using Container = std::list<Pointer>;

/*
    Fetching average price of cars from a collection of cars
*/

float AveragePriceOfCars(Container &data);

/*
    Push back the objects in Container
*/

void CreateObjects(Container &data);

/*
    Fetching average price of cars whose type match carType provided from a collection of cars
*/

float AveragePriceMatchCartype(Container &data, carType type);

/*
    - Fetching average price of all cars whose type match carType and carBrand
*/

float AveragePriceTypeAndBrand(Container &data, carType type, std::string Brand);

/*
 find and print all details of the car whose car price is maximum
*/

void FindMaximumPrice(Container &data);

/*
   Check whether all vehicles are of a type giveb as a parameter form a collection of cars
*/

bool CheckAllVehicleType(Container &data, carType type);

/*
Display Container
*/

void displayContainer(Container &data);