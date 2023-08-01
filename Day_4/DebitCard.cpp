#include "DebitCard.h"

DebitCard::DebitCard(int debitCardCVVnumber, std::string debitCardNumber, std::string debitCardExpiryDate)
    : debitCardCVVnumber(debitCardCVVnumber), debitCardNumber(debitCardNumber), debitCardExpiryDate(debitCardExpiryDate)
{
}

std::ostream &operator<<(std::ostream &os, const DebitCard &rhs)
{
    os << "debitCardCVVnumber: " << rhs.debitCardCVVnumber
       << " debitCardNumber: " << rhs.debitCardNumber
       << " debitCardExpiryDate: " << rhs.debitCardExpiryDate;
    return os;
}

DebitCard::~DebitCard()
{
    std::cout << "Debit card Number "
              << debitCardNumber
              << " has been deleted";
}