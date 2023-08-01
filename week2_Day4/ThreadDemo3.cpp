#include <iostream>
#include <thread>
#include <vector>



int main(){

    std::thread t1[3];
    std::vector<std::thread> vec(3);
    for(int i=0;i<3;i++){
        vec[i] = (std::thread([](){std::cout<<"Hello world\n";}));
    }
    for(int i=0;i<2;i++){
        vec[i].join();
    }
    // std::vector<int> v2(3);
    // for(int i=0;i<3;i++){
    //     v2[i] = i;
    // }
    // for(auto a : v2){
    //     std::cout<<a<<'\t';
    // }
}