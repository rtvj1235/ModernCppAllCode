#include <iostream>
#include "Functionalities.h"

int main(){
    Container data;
    CreateEngineeringStudentsObject(data);
    std::optional<Container> result = FindAbove10kScholarshipInstances(data);
    if(result.has_value()){
        for(auto & a : result.value()){
            std::visit([&](auto&& val){std::cout<<*val<<"\n";},a);
        }
    }
    std::optional<Container> result2 = FindAbove8CGPAInstances(data);
    if(result2.has_value()){
        for(auto& a : result2.value()){
            std::visit([&](auto&& val){std::cout<<*val<<"\n";},a);
        }
    }
}

// 1. A compiler may attend to move the value wherever applicable
// 2. starting from cpp 17 a compiler must alied a copy wherever applicable