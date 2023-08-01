#include <iostream>
#include <thread>
#include <mutex>

int amount = 1000;

std::mutex mt;


/*
things to search  CPP NUTS for threading playlist
mutex is one strategy for synchronization
lock gaurds and recursive lock unique locks try lock
*/

// for loop 100 times : each time withdraw 10 from amount
// for loop 100 times  : each time deposite 10 from amount

void deposite(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        mt.lock();
        amount = amount + 10;
        mt.unlock();
    }
}

void withdraw(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        mt.lock();
        amount = amount - 10;
        mt.unlock();
    }
}

int main(){
    std::thread t1(&deposite);
    std::thread t2(&withdraw);
    t1.join();
    t2.join();
    std::cout<<"Final answer is:"<<amount<<"\n";
}