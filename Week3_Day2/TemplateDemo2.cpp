/*
    variadic : varying or changing in terms of behaviour
*/

/*
    A function that can accept any number of arguments 0 to infinite 
    It should try to use + operator between 2 args of these and print final answer
    fun(10,20,30) : 50
    fun("harshit","shukla") : harshitshukla
    fun(10) :10
    fun() :0
    fun(10,20,30,40) : 20;


*/
#include <iostream>

template <typename T>
T add(T n){
    return n;
}
/*
    Function takes 1 argument of type T and a parameter Pack (...) of
    remianing args
    it recursively calls add with the parameter pack till we reach base case
*/

template <typename T, typename...ARGS>
T add(T n, ARGS... vals){
    return n + add(vals...);
}

int main(){
    int a = add<int>(10,20,30,40);
/*
Recursion tree for above call
1 n= 10  + add(20,30,40)
                20 + add(30,40)
                        30 + add(40)    // In this call it will call add function number 1 which will return n
                                40
*/
    std::cout<<a<<"\n";
    std::cout<< add<float>(10.0f,3.0f,30.5f)<<"\n";

}


