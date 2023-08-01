#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Account.h"
#include <iostream>
#include <list>
#include <memory>
#include "Account.h"
#include "AccountType.h"
#include "Bank.h"

using container = std::list<std::unique_ptr<Account>>;

void createObjects(container &data);

void displayAccount(container &data);

#endif // FUNCTIONALITIES_H


