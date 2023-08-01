#include "Account.h"

Account::Account(long number, float balance, AccountType type, float minbalance, std::unique_ptr<DebitCard>& card)
    : accountNumber(number), accountBalance(balance), accountType(type), accountMinimumBalance(minbalance), accountDebitCard(card)
{
}

/*
    if accountDebitCard is not a null pointer, free the pointer for debit card
    show the msg and delte the account

*/

Account::~Account()
{
    // if (this->accountDebitCard != nullptr)
    // {
    //     free(this->accountDebitCard);
    // }

    std::cout << "Account with number: "
              << this->accountNumber
              << " is deleted.";
}

std::ostream &operator<<(std::ostream &os, const Account &rhs)
{
    os << "accountNumber: " << rhs.accountNumber
       << " accountBalance: " << rhs.accountBalance
       << " accountType: " << displayEnum(rhs.accountType)
       << " accountMinimumBalance: " << rhs.accountMinimumBalance;
    return os;
}

std::string displayEnum(AccountType value)
{
    if (value == AccountType::SAVINGS)
        return "SAVINGS";
    else if (value == AccountType::CURRENT)
        return "CURRENT";
    else
        return "SALARY";
}
