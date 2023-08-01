#include "Functionalities.h"

/*
    As we're doing upcasting in container we can store vehicle as well as car objects
    so before calculating average we need to check the object type
    we can check that using dynamic_cast as dynamic cast If the cast is successful,
     ynamic_cast returns a value of type target-type. If the cast fails and target-type is a pointer type,
    it returns a null pointer of that type. If the cast fails and target-type is a reference type,
    it throws an exception that matches a handler of type std::bad_cast.
    as we re using Car& so if the dynamic cast fails it will throw an exception of std::bad_cast
    that is how we get to know that it is car type object or vehicle type object
*/

//-------------------------------------------------------------------------------------


float AveragePriceOfCars(Container &data)
{
    float sum = 0.0f;
    for (Pointer &a : data)
    {
        sum += a->getVehiclePrice();
    }
    return sum / (float)data.size();
}

void CreateObjects(Container &data)
{

    data.emplace_back(std::make_unique<Car>("v12o1", 10000000.00f, "MARUTI", 4, carType::SUV));
    data.emplace_back(std::make_unique<Car>("102B", 19802378.00f, "KIA", 5, carType::SUV));
    data.emplace_back(std::make_unique<Vehicle>("102B", 19802378.00f));
    data.emplace_back(std::make_unique<Car>("103B", 982378.00f, "HYUNDAI", 4, carType::SUV));
    data.emplace_back(std::make_unique<Car>("104B", 182378.00f, "TATA", 4, carType::SUV));
    data.emplace_back(std::make_unique<Car>("105B", 192378.00f, "RENAULT", 4, carType::SUV));
    data.emplace_back(std::make_unique<Car>("106B", 19878.00f, "HONDA", 4, carType::SUV));
    data.emplace_back(std::make_unique<Car>("107B", 19823.00f, "HONDA", 4, carType::SUV));
    data.emplace_back(std::make_unique<Vehicle>("103B", 198378.00f));
}

float AveragePriceMatchCartype(Container &data, carType type)
{

    /*
         My approacch without checking


     float sum = 0.0f;
     for (Pointer &a : data)
     {
         if ((dynamic_cast<Car &>(*a)).getCarCategory() == type)
         {
             sum += a->getVehiclePrice();
         }
     }
     return sum / (float)data.size();
     */

    /*
         Approach with checking
    */
    float total = 0.0f;
    for (auto itr = data.begin(); itr != data.end(); itr++)
    {
        try
        {
            Car &obj = dynamic_cast<Car &>(**itr);
            if (obj.getCarCategory() == type)
            {
                total += obj.getVehiclePrice();
            }
        }
        catch (std::bad_cast &obj)
        {
            std::cout << "BAD_CAST"
                      << "\n";
        }
    }
    return total / data.size();
}



float AveragePriceTypeAndBrand(Container &data, carType type, std::string Brand)
{
    float sum = 0.0f;
    for (Pointer &a : data)
    {
        if (((dynamic_cast<Car &>(*a)).getCarCategory() == type) &&
            ((dynamic_cast<Car &>(*a)).getCarBrand() == Brand))
        {
            sum += a->getVehiclePrice();
        }
    }
    return sum / (float)data.size();
}

void FindMaximumPrice(Container &data)
{
    Container ::iterator itr;
    itr = data.begin();
    float max = 0.0f;
    for (auto it = data.begin(); it != data.end(); it++)
    {
        if ((*it)->getVehiclePrice() > max)
        {
            max = (*it)->getVehiclePrice();
            itr = it;
        }
    }
    std::cout << dynamic_cast<Car &>(*(*itr)) << "\n";
}

bool CheckAllVehicleType(Container &data, carType type)
{
    bool flag = true;
    for (Pointer &a : data)
    {
        if (dynamic_cast<Car &>(*a).getCarCategory() == type)
            flag = true;
        else
            flag = false;
    }
    if (flag)
        return true;
    else
        return false;
}

void displayContainer(Container &data)
{
    for (Pointer &a : data)
    {
        // std::cout<<*a<<'\n';
        std::cout << dynamic_cast<Car &>(*a) << "\n";
    }
}
