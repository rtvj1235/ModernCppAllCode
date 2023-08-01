
#include <iostream>
#include <optional>
#include <list>

/*
    1. A way to say function A VALUE  MAY OR MAY NOT EXIST
*/
/*
    Delayed intialization 
*/
std::optional<std::list<int>> magic(std::list<int>& data){

    std::list<int> result;
    for(auto val : data){
        if(val % 2 ==0){
            result.emplace_back(val);
        }

    }
    if(result.empty()){
        return {};   // THIS INDICATES OPTIONAL WRAPPER IS EMPTY !!
    }
    else{
        return result;
    }
}

int main()
{
    std::list<int> data {1,2,3,4};
    std::optional<std::list<int>> ans = magic(data);
    /*
        as a user confrim if the optional wrapper contain something!!
        or to access the element in the list if it is there 
        we need to use the below syntax 
        first we check if there is any data using .has_value() function
        then we can use for loop
        .value() ---> access value inside the wrapper
    */
    if(ans.has_value()){
        for(auto val : ans.value()){
            std::cout<< val <<"\n";
        }
    }

}