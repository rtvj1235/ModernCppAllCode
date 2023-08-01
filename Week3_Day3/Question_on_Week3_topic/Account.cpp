#include "Account.h"

Account::Account(std::variant<std::string, int> accid, std::vector<Pointer> TransactionSet, float balance)
:accountId(accid),accountTransactionSet(TransactionSet),accountBalance(balance)
{}

Account::~Account()
{
    // std::cout<<"ACCOUNT DELETED\n";
}

std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "accountId: ";
    std::visit([](auto&& val){std::cout<<val<<" ";},rhs.accountId);
       os<< " accountTransactionSet:\n" ;
       for(auto & val:rhs.accountTransactionSet){
        std::cout<<*val<<"\n";

       }
       os<< " accountBalance: " << rhs.accountBalance;
    return os;
}

