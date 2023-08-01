#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <array>
#include <list>

class Account
{
private:
    /* data */
    int accountLastTranscationIds[5];
    std::array<int,5> accountLast5TransactionAmounts;
    std::list<std::string> accountChques;

public:
    Account(int transactinIds[5], std::array<int,5> amounts, std::list<std::string> cheques)
    /*
        HERA INSTEAD OF MOVE WE CAN STILL COPY THE DATA BUT AS WE ARE PASSING TEMPORARY VALUE
        FIRST THE ARRAY WILL COPY IN THE AMOUNTS AND THEN IN OUR DATA MEMBER
        Due to that till the constructor ends amount variable still holds the data as
        temprary values are alive till sequence point to avoid this we can move the data
    */
    :accountLast5TransactionAmounts(std::move(amounts))       
    {
        for(int i=0;i<5;i++){
            this->accountLastTranscationIds[i] = transactinIds[i];
        }
    }
    ~Account() {}
};

#endif // ACCOUNT_H
