/*
    int n1 = 10
    Any value which is stored in RAM has its own ADDRESS i.e a value which is addressable is
    called Lvalue 
    A value which is temporary value and has no reserved space in RAM is called an Rvalue


    A call to constructor returns an temporary i.e R value

    COPY SEMANTICS

        Reserve space equal to original data
        COPY all data from original location to new locaion
        SOMEHOW  delete original location's data

    MOVE SEMANTICS 


*/

#include<iostream>

class Demo
{
private:

    /* data */
    int val;
public:
    Demo(int d):val(d) {}
    ~Demo() {}
};

int main(){
    Demo(11); // call to constructor it returns Rvalue that is temporary
    new Demo(21);
    int arr1[3]={1,2,3};
    int *arr2 = arr1;
    for(int i=0;i<3;i++){
        std::cout<<*(arr2+i)<<"\t";
    }
    // delete arr1;
    // std::cout<<arr1[0]<<"\n";
}