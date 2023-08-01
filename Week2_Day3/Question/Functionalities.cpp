
#include "Vehicle.h"
#include "Car.h"
#include "Insurance.h"
#include <memory>
#include <list>
#include <functional>
#include "Functionalities.h"

/*
    A FUNCTION THAT RETURNS THE LIST OF CAR INSTANCES WHOSE INSURANCE AMOUNT IS OVER
     A THRESHOLD PROVIDED AS AN INPUT CONSIDER THE SCENARIO OF NO CARS BEING ABOVE THE INSURANCE
     AMOUNT THRESHOLD
*/
void tempfunction(){
    std::cout<<"thread function to tp\n";
}


auto In = std::make_shared<Insurance>("4",10000000.0f,InsuranceType::REGULAR);

std::function<void(InsuranceContainer& data)> CreateInsurance = [](InsuranceContainer& data){
    data.emplace_back(
        std::make_shared<Insurance>(
            "1",
            1000.0f,
            InsuranceType::REGULAR
        )
    );
    data.emplace_back(
        std::make_shared<Insurance>(
            "2",
            10000.0f,
            InsuranceType::ZERO_DEBT
        )
    );
    data.emplace_back(
        std::make_shared<Insurance>(
            "3",
            100000.0f,
            InsuranceType::REGULAR
        )
    );

};

/*
    A FUNCTION TO CREATE AN OBJECT OF CAR 
*/

std::function<void(Container& data,InsuranceContainer & Icontaier)> CreateObjects = []
    (Container& data, InsuranceContainer& Icontainer){
        CreateInsurance(Icontainer);
        InsuranceContainer :: iterator it;
        it = Icontainer.begin();
        data.emplace_back(
            std::make_shared<Car>(
                "V1",
                2001,
                VehicleType::COMMERCIAL,
                std::ref(*it),
                1000.0f,
                CarType::HATCHBACK,
                "BLACK"
            )
        );
        it++;
        data.emplace_back(
            std::make_shared<Car>(
                "V2",
                2002,
                VehicleType::PRIVATE,
                std::ref(*it),
                10000.0f,
                CarType::SEDAN,
                "WHITE"
            )
        );
        it++;
        data.emplace_back(
            std::make_shared<Car>(
                "V3",
                2003,
                VehicleType::SPECIAL_PRUPOSE,
                std::ref(*it),
                19338.0f,
                CarType::SEDAN,
                "RED"
            )
        );
        data.emplace_back(
            std::make_shared<Car>(
                "V4",
                2004,
                VehicleType::COMMERCIAL,
                std::ref(In),
                9839.0f,
                CarType::SEDAN,
                "Blue"
            )
        );
};

/*
    FUNCTION RETURN A CONTAINER CONTAINING CAR OBJECT 
    WHOSE INSURANCE AMOUNT IS OVER THERESHOLD AMOUNT PROVIDED AS PARAMETER
*/
std::function<Container(Container& data,float threshold)> InsuranceAmountOverThreshold =[](Container& data,float threshold){
    if(data.empty()){
        throw std::runtime_error("EMPTY");
    }

    Container temp;
    for(auto & a : data){
        if(a->getVehicleInsurancePlan().get()->getInsuranceAmount() > threshold){
            temp.emplace_back(a);
        }
    }
    return temp;

};


/*
     A FUNCTION THAT RETURN CARPRICE OF ALL CARS WHOSE VEHICLE TYPE MATCHES THE
     TYPE PASSED AS AN ARGUMENT 
     
*/

std::function<Container(Container& data, VehicleType type)> FindCarPriceMatchVehicleType =
    [](Container& data, VehicleType type){

        if(data.empty()){
            throw std::runtime_error("EMPTY");
        }
        Container temp;
        for(auto & a: data){
            if(a->getVehicleType() == type){
                temp.emplace_back(a);
            }
        }
        return temp;
};


/*
    A FUNCTION THAT RETURN A CAR COLOUR IN A CONTAINER FOR ALL CAR UNITS
    WHOSE VEHICLE TYPE IS PRIVATE 
*/
std::function<colourContainer(Container& data, VehicleType type)> FindCarColourByVehicleType =[]
    (Container & data, VehicleType type){

        if(data.empty()){
            throw std::runtime_error("EMPTY");
        }
        colourContainer temp;
        for(auto & a : data){
            if(a->getVehicleType() == type){
                temp.emplace_back(   dynamic_cast<Car*> (a.get())->getCarColour() );
            }
        }
        return temp;
    
};

/*
    A FUNCTION TO CALCULATE AVERAGE OF INSURANCE AMOUNT ACCORDING TO
    GIVEN CONDITION
*/
std::function<float(Container& data)> FindAverage =[](Container & data){

    if(data.empty()){
        throw std::runtime_error("EMPTY");
    }
    int n = 0;
    float sum = 0.0f;
    for(auto & a : data){
        if((a->getVehicleType() == VehicleType::COMMERCIAL) && a->getVehicleRegistrationyear() == 2023 &&
            a->getVehicleInsurancePlan().get()->getInsuranceType() == InsuranceType::ZERO_DEBT){
                sum += a->getVehicleInsurancePlan().get()->getInsuranceAmount();
                n++;
            }
    }
    return sum/n;

};




