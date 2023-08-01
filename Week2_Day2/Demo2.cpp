#include <iostream>
#include <functional>
#include <list>

using Box  = std::reference_wrapper<int> ;

int main(){
    int n1 =10;
    int n2 = 20;
    std::reference_wrapper<int> r1 {n1};
    std::reference_wrapper<int> r2{n2};
    std::reference_wrapper<int> r3{*new int(100)};
    std::list< Box > values {r1, r2,r3};
    std::cout<<r1.get()<<"\n";
    std::cout<<r1<<"\n";
    for(auto & a :values){
        std::cout<<a<<"\t";
    }


}