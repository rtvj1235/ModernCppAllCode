#include "Bank.h"
#include "Account.h"
#include "AccountType.h"

Bank::Bank(std::string name, std::string id) : bankName(name), bankId(id)
{
}

void Bank::TransferMoney(Account *senderMoney, Account *receiverMoney, float money)
{
    if (senderMoney->getAccountMinimumBalance() <= (senderMoney->getAccountBalance() - money))
    {
        std::cout << "\nHii\n";
        float amt = receiverMoney->getAccountBalance() + money;
        receiverMoney->setAccountBalance(amt);
    }
}

std::ostream &operator<<(std::ostream &os, const Bank &rhs)
{
    os << "bankName: " << rhs.bankName
       << " bankId: " << rhs.bankId;
    return os;
}
