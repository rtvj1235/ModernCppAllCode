#include <iostream>
#include <thread>
#include <vector>
#include <functional>


/*
    [10 20 30 40 50]
    create a thread equal to size of container .
    each thread should find the square of one number in the container

    VECTOR 
*/


std::function<void(int,int)> CreateObject(std::vector<int>& result){
    auto f1 = [&](int number,int i){result[i] = number * number;};
    return f1;
}

void ManageThread(std::vector<std::thread> & threadPool ,std::vector<int>& data, std::function<void(int,int)> f1){
    for(int i=0;i<5;i++){
        //loop for 5 times
        //replace thread in i position with a temporary thread(rvalue)
        // by using std::move
        // Each thread calls f1 and takes ith value from data
        threadPool[i] = std::move(std::thread(f1,data[i],i));
    }
    for(int i=0;i<5;i++){
        //joining in thread
        threadPool[i].join();
    }
}

void Display(std::vector<int>& results){
    //Displaying the result
    for(int val : results){
        std::cout<< val <<"\n";
    }
}


int main(){
    //Creating data and threadPool
    std::vector<int> data {10,20,30,40};
    std::vector<std::thread> threadPool(data.size());
    std::vector<int> results(data.size());
    auto f1 = CreateObject(results);
    ManageThread(threadPool,data,f1);
    Display(results);
    
    // //lambda to execute inside each thread
    // auto f1 = [&](int number,int i){results[i] = number * number;};


}

// concurrency in action
