#include <iostream>

/*
    I can call add with 0 or more number of parameters
    My Function should start addition (+ operation) with 0 and
    all parameters upto vals and return the answer
*/


/*

*/
template <typename... ARGS>
auto add (ARGS... vals){
    return (0+...+vals); // fold expressions!
}

template <typename... ARGS>
auto subtract(ARGS... vals){
    return (vals);  
}

int main(){
    /*
        IN flod expression ... decides associativity that means
        how our program is going to behave 
        in subtract function we wrote ... on the left side so it is
        going to solve like 
        ((10-20) - 30) = -10 -30 = -40;
    */
    std::cout<< subtract<int>(10,20,30); 
    /*
        IF we wrote ... on the right side of the val
        that is like
        return (vals - ....)
        this is going to solve like
        (10 - (20-30)) = 10 -- 10 answer will be 20;

        if we want to call fold expression on the empty parameters like 0 parameter 
        we need to have default for the fold
    */
//    std::cout<<subtract<int>(10,20,30)<<"\n";

}