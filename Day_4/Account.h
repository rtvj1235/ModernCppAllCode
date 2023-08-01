#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include "AccountType.h"
// #include"Bank.h"
#include "DebitCard.h"
#include <memory>

// Composition --> one new data member inside the acc class. the data member is called

class Account
{
private:
    long accountNumber;
    float accountBalance;
    AccountType accountType;
    const float accountMinimumBalance;
    std::unique_ptr<DebitCard>& accountDebitCard;

public:
    Account() = delete;
    Account(const Account &obj) = delete;
    Account(Account &&obj) = default;

    Account(long number, float balance, AccountType type, float minbalance, std::unique_ptr<DebitCard>& card );

    ~Account();

    long getAccountNumber() const { return accountNumber; }
    void setAccountNumber(long accountNumber_) { accountNumber = accountNumber_; }

    float getAccountBalance() const { return accountBalance; }
    void setAccountBalance(float accountBalance_) { accountBalance = accountBalance_; }

    AccountType getAccountType() const { return accountType; }
    void setAccountType(const AccountType &accountType_) { accountType = accountType_; }

    float getAccountMinimumBalance() const { return accountMinimumBalance; }

    std::unique_ptr<DebitCard>& getAccountDebitCard()  { return accountDebitCard; }
    // void setAccountDebitCard(const std::unique_ptr<DebitCard>& accountDebitCard_) { accountDebitCard = accountDebitCard_; }



    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
};

std::string displayEnum(AccountType value);

#endif // ACCOUNT_H
