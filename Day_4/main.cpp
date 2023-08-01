#include <iostream>
#include "Bank.h"
#include "Account.h"
#include "Functionalities.h"

// using container = std::list<Account*>;

int main()
{
    container data;

    createObjects(data);
    auto itr = data.begin();
    // Account* ac1 = *itr; //first
    // itr++;
    // Account* ac2 = *itr; //second

    // displayAccount(data);

    // Bank::TransferMoney(ac1, ac2, 2000.0f);
    // std::cout<<"\n\n--------------------------------------\n\n";
    // displayAccount(data);
}