#include <iostream>
#include "Employee.h"
#include "Student.h"


template<typename... ARGS>
auto Add(ARGS... val){
    return (...+val);
}

template<typename... ARGS>
auto subtract(ARGS... val){
    return (...-val);
}