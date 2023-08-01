#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "Engine.h"
#include <memory>

using Pointer = std::unique_ptr<Engine>;

class Car
{
private:
    /* data */
    std::string carBrand;
    Engine* carEngine;
    Pointer carSecondaryEngine;

public:
    Car(std::string Brand, Engine* primaryEngine, Pointer secondaryEngine) 
    :carBrand(Brand),carSecondaryEngine(std::move(secondaryEngine)),
    carEngine(primaryEngine)
    {}
    ~Car() {}
    void display()
    {
        std::cout<<carBrand<<"\n";
    }
    
};
#endif // CAR_H
