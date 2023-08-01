/*
    we cannot assign new variable to reference variable 
    the line below simply means n1 = n2 that means
    now the value of n1 is equal to n2
    WE CANNOT STORE REFERENCES IN THE LIST
    something which has its own memory we can store in the container 
    and reference variables do not have their own memory they are just alternate name for 
    original variable 
*/

#include <iostream>
#include <list>
int main(){
    int n1 = 10;
    int &data = n1; // data is now an ALTERNATE NAME for n1;
    int n2 = 0;
    int & t1 = n1;
    std::cout<< t1<<"\n";
    int& t2 = t1;
    std::cout<<t2<<"\n";
    data = n2; 
    int & v1= data;
    std::cout<<v1<<"\n";
    // std::cout<<n1<<"\n";
    // std::list<int> values{data};
    


}