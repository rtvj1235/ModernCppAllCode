#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include "Transaction.h"
#include <variant>
#include <vector>
#include <memory>

using Pointer = std::shared_ptr<Transaction>;

class Account
{
private:
    /* data */
    std::variant<std::string,int> accountId;
    std::vector<Pointer> accountTransactionSet;
    float accountBalance;
public:
    Account(/* args */) = delete;
    Account(const Account& obj)= delete;
    Account(Account&& obj) = delete;
    Account(std::variant<std::string ,int> accid,std::vector<Pointer> TransactionSet,float balance);
    ~Account() ;

    float getAccountBalance() const { return accountBalance; }
    void setAccountBalance(float accountBalance_) { accountBalance = accountBalance_; }

    std::variant<std::string,int> getAccountId() const { return accountId; }
    void setAccountId(const std::variant<std::string,int> &accountId_) { accountId = accountId_; }

    std::vector<Pointer> getAccountTransactionSet() const { return accountTransactionSet; }
    void setAccountTransactionSet(const std::vector<Pointer> &accountTransactionSet_) { accountTransactionSet = accountTransactionSet_; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
    
};

#endif // ACCOUNT_H
