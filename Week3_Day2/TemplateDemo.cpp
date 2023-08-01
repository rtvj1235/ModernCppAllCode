#include <iostream>
#include <list>
#include <vector>
#include <memory>

using Pointer = std::unique_ptr<int> ;

template <typename T>
void Display(T& data){
    for(auto & val : data){
        std::cout<<val<<"\t";
    }
}

/*
    Template Specialization 
*/
template<>
void Display(std::vector<Pointer>& data){
    for(auto & a : data){
        std::cout<<*a<<"\t";
    }
}

int main(){
    std::vector<int> v1 {10,20,30,40,50};
    std::list<int> L1 {10,20,30,40,50};
    std::vector<Pointer> V2;
        /*
            Here we changed unique ptr to shared ptr cause list 
            linitializer dosent work with move semantics 
            cause list initializer always use copy constructor
            if we want to use the unique pointer then we need to use 
            push_back instead of list initialization 
        */
        // std::make_shared<int>(10),
        // std::make_shared<int>(20),
        // std::make_shared<int>(30),
        // std::make_shared<int>(40),
        // std::make_shared<int>(50)
    
    V2.push_back(std::make_unique<int>(10));
    V2.push_back(std::make_unique<int>(20));
    V2.push_back(std::make_unique<int>(30));
    V2.push_back(std::make_unique<int>(40));
    V2.push_back(std::make_unique<int>(50));
    
    Display(v1);
    std::cout<<"\n";
    Display(V2);
    std::cout<<"\n";
    Display(L1);

}