#include <iostream>
#include "Car.h"
#include "Engine.h"

int main()
{
    Car* c1 = new Car(
        "Maruti",
        new Engine(700),
        std::make_unique<Engine>(800)
    );
    c1->display();

}
