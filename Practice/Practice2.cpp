
/*
     A DYNAMIC CAST ONLY CONVERTS BETWEEN RELATED CLASSES INSIDE THE INHERITANCE CHAIN
*/

#include <iostream>

#include <memory>

class Base
{
private:
    /* data */
public:
    Base(/* args */) {}
    virtual ~Base() {}
};

class Derived : public Base
{
private:
    /* data */
public:
    Derived(/* args */) {}
    ~Derived() {}
};


int main(){
    Base * bptr = new Derived;
    Derived * dptr = new Derived;

    if(dynamic_cast<Derived*>(bptr)){
        std::cout<<"SUCCESSFUL\n";
    }
    else{
        std::cout<<"NOT\n";
    }
    if(dynamic_cast<Base*>(dptr)){
        std::cout<<"agian ok\n";
    }
    else{
        std::cout<<"not ok\n";
    }
}