/*
    in one function , I need to take the input from the user for a numberd
    and to calculate square of input number
    and the other function need to display result

    In the main thread i need to print table of 2 upto 10 times
    along with creating threads for above funciton
*/

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

std::mutex mt;
std::condition_variable cv;
int number = 0;
int result = 0;

void TakeInputCalculateSquare(){
    std::cin>> number;
    std::lock_guard<std::mutex> lg(mt);
    result = number * number;  
    cv.notify_all();
}

void Display(){
    std::unique_lock<std::mutex> lu(mt);
    cv.wait(lu);
    std::cout<< result <<"\n";
}

int main(){
    std::thread t1 (&TakeInputCalculateSquare);
    std::thread t2 (&Display);


    for(int i =1;i<10;i++){
        std::cout<< "2 times "<< i<<" is:" << 2*i <<"\n";
    }
    t1.join();
    t2.join();
}