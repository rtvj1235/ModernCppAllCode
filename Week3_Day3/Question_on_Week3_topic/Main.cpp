#include <iostream>
#include "Account.h"
#include "Functionalities.h"
#include "Transaction.h"

int main(){
    AccContainer data;
    CreateAccount(data);
    // for(auto & a : data){
    //     std::cout<< *a <<"\n";
    // }
    TransContainer tdata;
    CreateTransaction(tdata);
    std::optional<int> count = countOfTransactionOfGivenType(tdata,TransactionType::CASH);
    if(count.has_value()){
        std::cout<< count.value() <<"\n";
    }

}