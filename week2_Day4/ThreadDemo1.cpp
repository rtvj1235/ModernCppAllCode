#include <iostream>
#include <thread>



void square(int number){
    std::this_thread::sleep_for(std::chrono::seconds(5));    // This will delay program run time for 5 seconds
    std::cout<<number * number<<"\n";
}

void cube(int number){
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<<number * number * number<<"\n";
}

int main(){
    // square(10);
    // cube(10);
    std::thread t1(&square,10);
    std::thread t2(&cube,10);

    /*
        Join function blocks main thread till t1 either finishes or throws an exception
    */
    t1.join();      
    t2.join();
    // std::this_thread::sleep_for(std::chrono::seconds(5));
}