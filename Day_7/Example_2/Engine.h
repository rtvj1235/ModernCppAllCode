#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

class Engine
{
private:
    /* data */
    int engineHorsePower;

public:
    Engine(int hp) : engineHorsePower(hp) {}
    ~Engine() 
    {
        std::cout<<"Engine Object Destroyed\n";
    }
};
#endif // ENGINE_H
