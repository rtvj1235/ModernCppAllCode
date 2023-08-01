#include <iostream>
#include <functional>   // A header for function programming features

/*
    std::fucntion<int(int)> fn which is wrapper for function pointer 
    same as int (*fn) (int)
*/

int(*f2)(int) = [](int a){return a;};


void magic(int number, std::function<int(int)>fn)
{
    std::cout<< fn(2)<<"\n";
    fn = [](int number){return number * number;};
    std::cout<<fn(3)<<"\n";
}


void magic2(int num, std::function<int(int ,int)>fn){
    std::cout<<fn(10,10)<<"\n";
    fn  = [](int a,int b){return a*b*2;};
    std::cout<<fn(1,2)<<"\n";

}

int main(){
//     magic( 100, [](int number){return number * 10;});
// //     magic(1000,99);
//     magic2(1,[](int num,int b){return num*b;});
    std::cout<<f2(10)<<"\n";
}
