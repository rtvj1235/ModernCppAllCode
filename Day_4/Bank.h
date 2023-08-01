#ifndef BANK_H
#define BANK_H
#include <iostream>
#include "Account.h"
#include "AccountType.h"
#include "Bank.h"

class Bank
{
private:
    std::string bankName;
    std::string bankId;

public:
    Bank() = delete;
    Bank(const Bank &obj) = default;
    Bank(Bank &&obj) = default;

    Bank(std::string name, std::string id);
    static void TransferMoney(Account *senderMoney, Account *receiverMoney, float money);

    ~Bank() {}

    friend std::ostream &operator<<(std::ostream &os, const Bank &rhs);
};

#endif // BANK_H
