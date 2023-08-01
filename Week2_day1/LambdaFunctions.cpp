/*
    We can create a lambda function inside a main function
*/

#include <iostream>

int square(int number){
    return number * number;
}

// f1 is a lvale that is binded to a lambda
auto f1 = [](int number){return number*number ;};


/*
    [] : capture parameters in lambda function
    WHAT IS USE OF [] IN LAMBDA FUNCTION 
    IN GENERAL A FUNCTION CAN ONLY ACCESS THE MEMBER WHOSE ARE LOCAL TO IT 
    BUT HERE NUMBER AND FACTOR MEMBER ARE NOT LOCAL FOR FN FUNCTION BUT THEY
    ARE LOCAL FOR THE ENCLOSING FUNCTION That is Magic      
    For that we use capture  parameter 

    [&] : capture all variables from enclosing function via reference
    [&Factor] : this only capture factor not the number via reference
    [&Factor , & number] : this will capture factor and number 
    [=] : capture all variables via value not a reference   
*/

void magic(int number){
    int factor = 10;
    // create a lambda for : take number and factor form magic and return number * factor

    auto fn = [&]() {return number * factor;};
    std::cout<<fn();
}

int main(){
    int a = 5,b=5;
    auto f2 = [](int number){return number * number * number;};
    std::cout<<f2(10)<<"\n";
    auto f3 = [&a](){ a = a+5 ;
    return 0;};

    magic(10);
}