#include <iostream>
#include <functional>


int square(int number){
    return number * number;
}

int cube(int number){
    return number * number * number;
}

/*
    PASSING FUNCTION AS PARAMETER IN ANOTHER FUNCTION
    A function that takes an array of 5 integers
    AND
    a function that takes an integer and returns an integer
*/

/*
    In this example we have passed first parameter as int 
    and second parameter as function now here we are passing
     a function that takes one parameter as integer and 
     returns the one integer so now we can pass square and cube as 
    well to the operation function
    the only condition is that signature should be same 
*/

void operation(int *arr, /* int(*fn)(int) */ std::function<int(int)> fn)  
{
    for(int i=0;i<5;i++)
    {
        std::cout<< fn(arr[i]) <<"\n";
    }
}

int main()
{
    int data[5] = {1,2,3,4,5};
    operation(data, square); //operation will give square of each number in tha array
    operation(data, cube); ///cube of each number in the array

}