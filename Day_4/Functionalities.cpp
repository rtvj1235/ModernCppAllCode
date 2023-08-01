#include <iostream>
#include "Functionalities.h"
#include "Account.h"
#include "AccountType.h"
#include "Bank.h"

void createObjects(container &data)
{
    data.emplace_back(
        std::make_unique<Account>(1230001,
                                  50000.0f,
                                  AccountType::SAVINGS,
                                  5000.0f,
                                  std::make_unique<DebitCard>(999, "1121 3131 3133", "09/29")));

    // data.emplace_back(std::make_unique<Account>(1230021, 60000.0f, AccountType::SAVINGS, 5000.0f));
    // data.emplace_back( new Account(1230031, 500000.0f, AccountType::SAVINGS, 5000.0f) );
    // data.emplace_back( new Account(1230041, 600000.0f, AccountType::SAVINGS, 5000.0f) );
}

void displayAccount(container &data)
{
    for (auto &itr : data)
    {
        std::cout << "\nAccount Number: " << itr->getAccountNumber();
        std::cout << "\nAccount Balance: " << itr->getAccountBalance();
    }
}
