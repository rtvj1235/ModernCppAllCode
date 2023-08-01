#include <iostream>
#include <thread>
#include <mutex>

std::mutex mt;
int ans = 0;
void divide(){
    int n1 = 10;
    int n2 = 0;
    mt.lock();
    try{
        /*
            In this code we are locking using mutex lock but as ans = n1 / n2 and n2 = 0
            it will throw an exception that is float pointer exception (divide by 0)
            and as we know as soon as we get exception the line below exception
            will not run hence mt.unlock will not work and our program will 
            get deadlock as it didn't unlock 
            this will avoided by using lock_gaurd as it will get destructed at the end of scope
            that means after the exception try block will end and as we are using lock_gaurd it will
            automatically unlock or get destructed
            
        */
        ans = n1 /n2;
        mt.unlock();
    }
    catch(...){
        std::cout<< "EXCEPTION CAUGHT\n";
    }
    std::cout<< ans <<"\n";
}


int main(){

}