#include <iostream>
#include <functional>

int square(int n){
    return n*n;
}
int main(){
    
    std::function<int(int)> f1 = square;
    std::cout<<f1(2)<<"\n";
    int(*ptr)(int) = square;
    std::cout<<ptr(3)<<"\n";

}