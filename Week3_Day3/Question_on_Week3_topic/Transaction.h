#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "TransactionType.h"
#include <variant>


class Transaction
{
private:
    /* data */
    std::variant<std::string , float > transactionId;
    float transactionAmount;
    TransactionType transactionType;
    
public:
    Transaction(/* args */) = delete;
    Transaction(std::variant<std::string , float >,float amount, TransactionType transactionType_);
    Transaction(const Transaction& obj) = delete;
    Transaction(Transaction&& obj) = delete;
    ~Transaction();

    std::variant<std::string , float > getTransactionId() const { return transactionId; }
    void setTransactionId(const std::variant<std::string , float > &transactionId_) { transactionId = transactionId_; }

    float getTransactionAmount() const { return transactionAmount; }
    void setTransactionAmount(float transactionAmount_) { transactionAmount = transactionAmount_; }

    TransactionType getTransactionType() const { return transactionType; }
    void setTransactionType(const TransactionType &transactionType_) { transactionType = transactionType_; }

    friend std::ostream &operator<<(std::ostream &os, const Transaction &rhs);
};


std::string DisplayTransactionType(TransactionType type);
#endif // TRANSACTION_H
