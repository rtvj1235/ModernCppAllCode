#ifndef BILL_H
#define BILL_H
#include <functional>
#include <iostream>
#include "Invoice.h"
#include <memory>


using Reference = std::reference_wrapper<std::shared_ptr<Invoice>>;

class Bill
{
private:
    /* data */
    float billAmount;
    float billTaxAmount;
    Reference billAssociatedInvoice;

public:
    Bill() = delete;
    Bill(float amount, float tax, Reference associatedInvoice);
    Bill(const Bill & oj) = default;           
    Bill(Bill && obj) = delete;
    Bill& operator=(const Bill & obj) = default;
    ~Bill();           

    Reference getBillAssociatedInvoice() const { return billAssociatedInvoice; }
    void setBillAssociatedInvoice(const Reference &billAssociatedInvoice_) { billAssociatedInvoice = billAssociatedInvoice_; }

    float getBillTaxAmount() const { return billTaxAmount; }
    void setBillTaxAmount(float billTaxAmount_) { billTaxAmount = billTaxAmount_; }

    float getBillAmount() const { return billAmount; }
    void setBillAmount(float billAmount_) { billAmount = billAmount_; }

    friend std::ostream &operator<<(std::ostream &os, const Bill &rhs);
};

#endif // BILL_H
