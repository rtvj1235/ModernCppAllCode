#include "Functionalities.h"
#include "Car.h"
#include "Bike.h"
#include "Vehicle.h"
#include "BikeCategories.h"
#include "CarCategories.h"


float AveragePrice(Vehicle **ptr, int N)
{
    float total=0.0f;
    for(int i=0;i<N;i++){
        total+= ptr[i]->getVehiclePrice();
    }
    return total/N;
}

/*

    We will take input N from the user reserve space
    to store N pointers together on the heap
    ( array of Pointers/Poiter to pointer)
    Here weve declared pointer to pointer of clas vehicle so that we
    can make the objects of the bike as well as car using same createObject function

*/

Vehicle **ReserveSpace(int N)
{
    Vehicle **ptr = new Vehicle *[N];
    return ptr;
}

/*
    CHILD ITEM ----> ATTACHED TO PARENT POINTER / REFERENCE (UPCASTING)
    PARENT ITEM -----> ATTACHED TO CHILD POINTER / REFERENCE (DOWNCASTING)
*/

void createObjects(int N, Vehicle **ptr)
{
    ptr[0] = new Car("MR101","Maruti",10920839.0f,"DIZRE",carType::SEDAN);
    ptr[1] = new Car("MR102","NISSAN",1092089.0f,"MAGNITE",carType::SUV);
    ptr[1] = new Bike("MR103","HONDA",122089.0f,BikeType::OFFRAODER);
    
}


std::string FindMaxPriceVehicleId(Vehicle** ptr, int N){
    float maxaPrice = 0.0f;
    std::string temp = "";
    for(int i=0;i<N;i++){
        if( ptr[i]->getVehiclePrice() > maxaPrice)
        {
            maxaPrice = ptr[i]->getVehiclePrice();
            temp = ptr[i]->getVehicleId();
        }
    }
    return temp;
}


/*
    Loop Over all car objects received '
    if car is of type mentionded by the user add its price to the total
*/
float FindCombinedPrice(Vehicle **ptr, int N, carType type)
{
    float total =0.0f;
    for(int i=0;i<N;i++){
        if(((Car*)ptr[i])->carType() == type){
            total += ptr[i]->getVehiclePrice();
        }
    }
    return total;
}

float FindCombinedPrice(Vehicle **ptr, int N, BikeType type)
{
        float total =0.0f;
    for(int i=0;i<N;i++){
        if(((Bike*)ptr[i])->getBtype() == type){
            total += ptr[i]->getVehiclePrice();
        }
    }
    return total;
}
