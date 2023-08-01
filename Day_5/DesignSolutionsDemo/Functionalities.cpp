#include "Functionalities.h"

void CreateDataValues(Container &data)
{
    data.emplace_back(std::make_unique<int>(10));
    data.emplace_back(std::make_unique<int>(20));
    data.emplace_back(std::make_unique<int>(30));
    data.emplace_back(std::make_unique<int>(40));
    data.emplace_back(std::make_unique<int>(50));
    data.emplace_back(std::make_unique<int>(60));
    data.emplace_back(std::make_unique<int>(70));
    data.emplace_back(std::make_unique<int>(80));
}

int Minvalue(Container &data)
{
    Container :: iterator it;
    it = data.begin();
    int temp = *(*it);
    for(Pointer& a : data){
        if(*a < temp){
            temp = *a;
        }
    }

    return temp;
}

int MaxValue(Container &data)
{
    Container :: iterator it;
    it = data.begin();
    int temp = *(*it);
    for(Pointer& a:data){
        if(*a > temp){
            temp = *a;
        }
    }
    return temp;
}

int TotalSize(Container &data)
{
    return data.size();
}

int AddNumber(Container &data,int number)
{
    // data.emplace_back(std::move(number));
    data.emplace_back(std::make_unique<int>(number));
}

void RemoveNumber(Container &data,int number)
{
    Container :: iterator it;
    for(it = data.begin();it!= data.end();it++){
        if(*(*it)==number){
            break;
        }
    }
    data.erase(it);
    
}

void display(Container &data)
{
    for(Pointer& a : data){
        std::cout<<*a<<" ";
    }
}
