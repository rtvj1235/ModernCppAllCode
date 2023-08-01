#include <iostream>
#include <list>

std::list<int> maginc(std::list<int>& data){
    std::list<int> result;
    for(auto val : data){
        if(val % 2 == 0){
            result.push_back(val);
        }
    }
    return result;
}

void more_magic(std::list<int>& ans){
    std::cout<< ans.front() <<"\n";
}

int main(){
    std::list<int> data {1,3,5,7,9};
    auto ans = maginc(data);

    more_magic(ans);
}