#include <iostream>

int  Fact(int n){
    if(n==1){return 1;}
    else{
        return n* Fact(n-1);
    }

}

int main(){
    int n = Fact(3);
    std::cout<<n<<"\n";
}