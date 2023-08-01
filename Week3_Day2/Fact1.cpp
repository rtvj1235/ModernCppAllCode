#include <iostream>

int main()
{
    int n = 3;
    int result = 1;
    for(int i=2;i<=3;i++){
        result *= i;
    }
    std::cout<<result<<"\n";
}