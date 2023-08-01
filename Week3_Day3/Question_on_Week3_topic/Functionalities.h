#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Transaction.h"
#include "TransactionType.h"
#include "Account.h"
#include <memory>
#include <list>
#include <variant>
#include <optional>


using AccountPointer = std::shared_ptr<Account>;
using TransactionPointer = std::shared_ptr<Transaction>;
using AccContainer = std::list<AccountPointer>;
using TransContainer = std::list<TransactionPointer>;



/*
    A FUNCTION TO CREATE AN OBJECT OF ACCOUNT TYPE
*/

void CreateAccount(AccContainer& data);

/*
    A function to create Transaction object
*/

void CreateTransaction(TransContainer& data);

/*
    A Function countTransactionOfGivenType that takes a container
    of Transaction object pointers and return a count of Transaction
    instances whose transaction type matches with the argument given as
    the second parameter
*/

std::optional<int> countOfTransactionOfGivenType(TransContainer& data, TransactionType type);

/*
A function totalTransactionAmount that takes a container of acocunt instances and
return a total of transactionAmoun for all instances
*/

float totalTransactionAmount(AccContainer& data);

/*
    A function findMaxAccountBalanceId that takes a data container of account instances
    and a transaction Type and finds the id of the account that hass the highest
    balance amongst all accounts whose transactiontype matches with 
    the type passed as a argument
*/

std::variant<std::string,int> FindMaxAccountBalanceId(AccContainer& data,TransactionType type);

/*
    A function accountsAboveThreshold that takes a threshold amount and returns
    a data conatainer of all account instances whose cumulative transactionAmount
    is above threshold passed
*/
std::optional<AccContainer> accountAboveThreshold(AccContainer& data,float threshold);

/*
    A function nthTransactionId that return the id of the nth transaction of an account
    instance from a data container of account instances whose cumulative transactionAmount
    is above threshold passed
*/

std::variant<std::string,float> nthTransactionId(AccContainer& data,int n,std::variant<std::string,int> accid);

/*
    A function averageTransactionAmount that returns the average of transactionAmount
    for all Account instances whose ID values are passed in a data container as parameter
*/

float AverageTransactionAmount(AccContainer& data,std::vector<std::variant<std::string,int>> idcotainer);

/*
    A function balanceInterestAmount that runs in a thread and return the cumulative intreset 
    for all accounts whose instances are passed in data container
*/

std::optional<float> balanceInterestAmount(AccContainer& data);

/*
    A function is accountValid that return true or false based on the following 
*/

bool isAccountValid(AccContainer& data);



#endif // FUNCTIONALITIES_H
