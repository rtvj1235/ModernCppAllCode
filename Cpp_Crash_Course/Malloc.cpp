#include<iostream>
using namespace std;

/*
    Allocates Memory for 5 interger values of heap
*/
int * ALlocateMemory(int size)
{
    int * arr= (int *)malloc(20);
    return arr;
}

/*
    Access ith position of malloc block 
    put i+1 value in each position
*/

void FillValue(int * arr)
{
    for(int i=0;i<5;i++){
        *(arr+i) = i+1;
    }
}

/*
    Loop over each location and print the data using std::cout
*/

void DisplayValue(int * arr){
    for(int i=0;i<5;i++){
        std::cout<<*(arr+i)<<"\t";
    }
}

/*
    Free the memory using free
*/
void FreeMemory(int *arr){
    free(arr);
}


int main()
{
    int * arr = ALlocateMemory(20);
    FillValue(arr);
    DisplayValue(arr);
    FreeMemory(arr);

}




