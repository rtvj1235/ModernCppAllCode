#include <iostream>
#include <vector>
#include <list>
#include <any>
#include <array>

std::any data;


// template <typename T>

auto CreateContainer(){
    int choice =0;
    std::cin >> choice;
    switch (choice)
    {
    case 1: 
        data = std::vector<int> {1,2,3,4,5};
        break;
    case 2 :
        data = std::list<int> {1,2,3,4,5};
        break;
    case 3 :
        data = std::array<int,5> {1,2,3,4,5};
        break;
    default :
        data = "";
        break;
    }
    
}

int main(){
    CreateContainer();
}