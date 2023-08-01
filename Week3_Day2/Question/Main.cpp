#include <iostream>
#include <memory>


#include "Functionalities.h"

int main(){
    std::unique_ptr<Student> s1 = std::make_unique<Student>(1,"akshay",20.0f);
    std::unique_ptr<Student> s2= std::make_unique<Student>(4,"akshay",30.0f);
    std::unique_ptr<Student> s3 = std::make_unique<Student>(3,"akshay",40.0f);
    std::unique_ptr<Student> s4 = std::make_unique<Student>(2,"akshay",50.0f);
    std::cout<<Add<Student>(*s1,*s2,*s3,*s4)<<"\n";
    std::cout<<subtract<Student>(*s1,*s2,*s3,*s4)<<"\n";

    // Employee e1(1,"a",1);
    // Employee e2(2,"b",2);
    // Employee e3(3,"c",3);
    // Employee e4(4,"d",4);
    // Employee e5(5,"e",5);
    // std::cout<<Add<Employee>(e1,e2,e3,e4)<<"\n";
    // std::cout<<subtract<Employee>(e1,e2,e3,e4)<<"\n";

}