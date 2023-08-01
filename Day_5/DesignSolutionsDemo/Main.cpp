#include <iostream>

#include "Functionalities.h"

int main(){
    Container data;
    CreateDataValues(data);
    std::cout<<Minvalue(data)<<"\n";
    RemoveNumber(data,20);
    display(data);
    AddNumber(data,50);
    std::cout<<"\n";
    display(data);
    std::cout<<"\n";
    std::cout<<MaxValue(data)<<"\n";
}