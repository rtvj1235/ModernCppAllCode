#include "Transaction.h"

std::string DisplayTransactionType(TransactionType type)
{
    if(type == TransactionType ::CARD) {return "CARD";}
    else if(type == TransactionType ::CASH){return "CASH";}
    else{
        return "UPI";
    }
}

Transaction::Transaction(std::variant<std::string, float> id, float amount, TransactionType transactionType_)
:transactionId(id),transactionAmount(amount),transactionType(transactionType_)
{}

Transaction::~Transaction()
{
    // std::cout<<"TRANSACTION DELETED\n";
}

std::ostream &operator<<(std::ostream &os, const Transaction &rhs) {
    os << "transactionId: " ;
    std::visit([](auto&& val){std::cout<<val<<" ";},rhs.transactionId);
       os<< " transactionAmount: " << rhs.transactionAmount
       << " transactionType: " << DisplayTransactionType(rhs.transactionType);
    return os;
}
