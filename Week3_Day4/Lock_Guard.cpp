
/*
    Lock_Gaurd (smarter version of mutex)
*/
/*
    How joins behave it holds main untill all thread has completed their operation
    join doesn't start the thread we write a join command to check whether the thread
    is completed or not if its not it will hold main function 

    What is Race Condition------->
    Race condition happens when two or more thread are doing a write operation 
    on shared memory in our case amount variable is common (shared memory)

    Daigram
            [first 
            for 
            loop 
           start]
                
    start-----o------------------------------------------------------------------------------end

    main part        ---------o------------------
    2nd for                   [2nd for 
    loop starts              loop starts
                            simultaneously]
    
*/
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mt;

int amount = 100;


int main(){
    std::thread arr[100]; // default construction 100 threads
    std::thread arr2[100];
    for(int i =0;i<100;i++){
        arr[i] = std::move(
            std::thread(
            [](){
                    /*
                        Here we are creating a lock guard object by passing mutex to it
                        lock is name of object here it will check the scope of the function i.e bracktes 
                        in which it includes and it will automacilly apply lock and unlock to avoid race 
                        condition
                    */
                    std::lock_guard<std::mutex> lock(mt);
                    amount++;
                }
            )
        );
    }

    for(int i =0;i<100;i++){
        arr2[i] = std::move(
            std::thread(
            [](){
                std::lock_guard<std::mutex> lock(mt);
                amount--;
                }
            )
        );
    }
    for(int i=0;i<100;i++){
        arr[i].join();
        arr2[i].join();
    }

    std::cout<< "amount:"<<amount<<"\n";
}