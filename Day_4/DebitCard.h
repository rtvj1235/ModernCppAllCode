#ifndef DEBITCARD_H
#define DEBITCARD_H
#include <iostream>

class DebitCard
{
private:
    int debitCardCVVnumber;
    std::string debitCardNumber;
    std::string debitCardExpiryDate;

public:
    DebitCard() = delete;
    DebitCard(const DebitCard &obj) = delete;
    DebitCard(DebitCard &&obj) = default;

    DebitCard(int debitCardCVVnumber, std::string debitCardNumber, std::string debitCardExpiryDate);

    ~DebitCard();

    int getDebitCardCVVnumber() const { return debitCardCVVnumber; }
    void setDebitCardCVVnumber(int debitCardCVVnumber_) { debitCardCVVnumber = debitCardCVVnumber_; }

    std::string getDebitCardNumber() const { return debitCardNumber; }
    void setDebitCardNumber(const std::string &debitCardNumber_) { debitCardNumber = debitCardNumber_; }

    std::string getDebitCardExpiryDate() const { return debitCardExpiryDate; }
    void setDebitCardExpiryDate(const std::string &debitCardExpiryDate_) { debitCardExpiryDate = debitCardExpiryDate_; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
};

#endif // DEBITCARD_H
