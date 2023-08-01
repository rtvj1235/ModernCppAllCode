#include "Functionalities.h"
#include <thread>


/*
    Global objects of Transaction
*/
auto T1 = std::make_shared<Transaction>("1",1000.0f,TransactionType::CARD);
auto T2 = std::make_shared<Transaction>("2",10004.0f,TransactionType::CASH);
auto T3 = std::make_shared<Transaction>(3.20f,10300.0f,TransactionType::UPI);
auto T4 = std::make_shared<Transaction>("4",10300.0f,TransactionType::CARD);
auto T5 = std::make_shared<Transaction>(3.0f,10300.0f,TransactionType::CASH);
auto T6 = std::make_shared<Transaction>(2.0f,1340300.0f,TransactionType::UPI);
auto T7 = std::make_shared<Transaction>(4.0f,3004.0f,TransactionType::CARD);
auto T8 = std::make_shared<Transaction>(5.20f,100.0f,TransactionType::CASH);


/*
    A FUNCTION TO CREATE AN OBJECT OF ACCOUNT TYPE
*/

void CreateAccount(AccContainer &data)
{
    data.emplace_back(
        std::make_shared<Account>(
            "AC1",
            std::vector<Pointer>{T1,T2,T3},
            2000000.0f
        )
    );
    data.emplace_back(
        std::make_shared<Account>(
            2,
            std::vector<Pointer>{T3,T4},
            200000.0f
        )
    );
    data.emplace_back(
        std::make_shared<Account>(
            "AC2",
            std::vector<Pointer>{T5,T6},
            82888.0f
        )
    );
    data.emplace_back(
        std::make_shared<Account>(
            3,
            std::vector<Pointer>{T7,T8},
            393939.3f
        )
    );
}

/*
    A function to create Transaction object
*/

void CreateTransaction(TransContainer &data)
{
    data.emplace_back(
        std::make_shared<Transaction>(
            2.0f,
            2922.0f,
            TransactionType::CARD
        )
    );
    data.emplace_back(
        std::make_shared<Transaction>(
            "2",
            20202.0f,
            TransactionType::CASH
        )
    );
    data.emplace_back(
        std::make_shared<Transaction>(
            3.4f,
            9000.0f,
            TransactionType::UPI
        )
    );
}

/*
    A Function countTransactionOfGivenType that takes a container
    of Transaction object pointers and return a count of Transaction
    instances whose transaction type matches with the argument given as
    the second parameter
*/

std::optional<int> countOfTransactionOfGivenType(TransContainer &data, TransactionType type)
{
    if(data.empty()){
        throw std::runtime_error("EMPTY");
    }
    int count = 0;
    for(auto & a : data){
        if(type == a->getTransactionType()){
            count++;
        }
    }
    if(count==0){
        throw std::runtime_error("ENTER VALID TYPE");
    }
    else{
        return count;
    }
}

/*
    A function totalTransactionAmount that takes a container of acocunt instances and
    return a total of transactionAmoun for all instances
*/

float totalTransactionAmount(AccContainer &data)
{
    float sum = 0.0f;
    for(auto & a : data){
        for(auto& b : a->getAccountTransactionSet()){
            sum += b->getTransactionAmount();
        }
    }
    return sum;
}

/*
    A function findMaxAccountBalanceId that takes a data container of account instances
    and a transaction Type and finds the id of the account that hass the highest
    balance amongst all accounts whose transactiontype matches with 
    the type passed as a argument
*/

std::variant<std::string, int> FindMaxAccountBalanceId(AccContainer &data, TransactionType type)
{
    if(data.empty()){
        throw std::runtime_error("EMPTY");
    }
    std::variant<std::string,int> id;
    for(auto & a : data){
        for(auto & b : a->getAccountTransactionSet()){
            if(b->getTransactionType() == type){
                // std::visit([&](auto&& val){id = val->getTransactionId();});
                id = a->getAccountId();
            }
        }
    }
    return id;

}

/*
    A function accountsAboveThreshold that takes a threshold amount and returns
    a data conatainer of all account instances whose cumulative transactionAmount
    is above threshold passed
*/

std::optional<AccContainer> accountAboveThreshold(AccContainer &data, float threshold)
{
    if(data.empty()){
        throw std::runtime_error("EMPTY");
    }
    float sum = 0.0f;
    int n =0;
    AccContainer result;
    for(auto& a : data){
        for(auto & b : a->getAccountTransactionSet()){
            sum += b->getTransactionAmount();
            n++;
        }
        if(sum/n > threshold){
            result.emplace_back(a);
        }
    }
    if(result.empty()){
        return {};
    }
    else{
        return result;
    }

}

/*
    A function nthTransactionId that return the id of the nth transaction of an account
    instance from a data container of account instances whose cumulative transactionAmount
    is above threshold passed
*/

std::variant<std::string, float> nthTransactionId(AccContainer &data, int n, std::variant<std::string, int> accid)
{
    if(data.empty()){
        throw std::runtime_error("EMPTY");
    }
    std::variant<std::string,float> result;
    // int n = 0;
    for(auto & a : data){
        if(a->getAccountId()== accid){
            for(auto & b : a->getAccountTransactionSet()){
               result = a->getAccountTransactionSet()[n]->getTransactionId();
            }
        }
    }
    return result;
}


/*
    A function averageTransactionAmount that returns the average of transactionAmount
    for all Account instances whose ID values are passed in a data container as parameter
*/

float AverageTransactionAmount(AccContainer &data,std::vector<std::variant<std::string,int>> idcotainer)
{
    float sum = 0.0f;
    int n = 0;
    for(auto & a : data){
        for(auto& b : idcotainer){
            if(a->getAccountId() == b){
                for(auto & c : a->getAccountTransactionSet()){
                    sum += c->getTransactionAmount();
                    n++;
                }
            }
        }
    }
    return sum/n;
}

/*
    A function balanceInterestAmount that runs in a thread and return the cumulative intreset 
    for all accounts whose instances are passed in data container
*/

std::optional<float> balanceInterestAmount(AccContainer &data)
{
    float interest = 0.0f;
    for(auto & a : data){
        if(a->getAccountBalance() > 10000){
            interest += 0.04f * a->getAccountBalance();
        }
        else{
            interest += 0;
        }
    }
    if(interest){
        return interest;
    }
    else{
        throw std::runtime_error("NO INSTANCE HAVE BALANCE OVER 10000");
    }
}

// bool isAccountValid(AccContainer &data)
// {
//     bool flag = true;
//     for(auto & a : data){
//         if(a->getAccountBalance() > 10000 && (a->getAccountTransactionSet().size() > 3)){
//             flag = true;
//         }
//         for(auto & b : a->getAccountTransactionSet()){
//             if(b->getTransactionAmount() > 500){
//                 flag = true;
//             }
//         }
//     }
// }
