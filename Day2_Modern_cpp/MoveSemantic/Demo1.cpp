#include<iostream>
/*
    Transefering n1 to a function that calculats square of the number
*/

int Square(int number){
    return number * number;
}

//Take lvalue reference of something and call reference as "Number"
// A const lvalue reference can BIND  to the lvalue as well as rvalue
int Square(int & number){
    return number * number;
}

/*
    EXAMPLE OF MOVE SEMANTICS
    Take a reference of a temporary and assign it to number 
    int square(int && number)
    return number*number
*/
int Square(int && number){
    return number*number;
}


int main()
{
    
}