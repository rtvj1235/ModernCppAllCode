
#include"Vehicle.h"

/*
    Average price to calculagte average of vehiclePrice for an array of vehicle objects stored on heap
*/

float AveragePrice(Vehicle** ptr, int N);
/*
    FINF THE VEHICLE ID OF VEHICLE WITH MAXIMUM VEHICLE PRICE AND RETRUN
    THE ID
*/

std::string FindMaxPriceVehicleId(Vehicle** ptr, int N);


/*
    Find and return total combined price from an array
    of vehicle objects whose type match the second parameter passed by the user
*/

float FindCombinedPrice(Vehicle** ptr,int N, carType type);

float FindCombinedPrice(Vehicle** ptr,int N, BikeType type);


/*
    Functionality to create space on heap for N objects 
    shere N  is the number of objects to be stored
*/

Vehicle** ReserveSpace(int N);


/*
    Functionality to create objects and store on heap'

*/

void createObjects(int N, Vehicle** ptr);


/*
    Switch menu to present available functionalities 
    After objects are created
*/

