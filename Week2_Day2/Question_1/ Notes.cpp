#include <iostream>
#include <list>

void magin(int n)
{
    std::cout<<"Adress of n:"<<&n<<"\n";    
}

int main(){
    int n =10;
    std::cout<<"Adress of n in main:"<<&n<<"\n";
}