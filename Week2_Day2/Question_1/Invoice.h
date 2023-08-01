#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include "InvoiceType.h"
class Invoice
{
private:
    /* data */
    std::string invoiceNumber;
    InvoiceType invoiceType;
    int invoiceItems;
public:
    Invoice() = delete;
    Invoice(const Invoice& obj) = default;
    Invoice (Invoice&& obj) = delete;
    Invoice& operator=(const Invoice& obj) = default;
    Invoice(std::string number, InvoiceType type , int items);
    ~Invoice();

    std::string getInvoiceNumber() const { return invoiceNumber; }
    void setInvoiceNumber(const std::string &invoiceNumber_) { invoiceNumber = invoiceNumber_; }

    InvoiceType getInvoiceType() const { return invoiceType; }
    void setInvoiceType(const InvoiceType &invoiceType_) { invoiceType = invoiceType_; }

    int getInvoiceItems() const { return invoiceItems; }
    void setInvoiceItems(int invoiceItems_) { invoiceItems = invoiceItems_; }

    friend std::ostream &operator<<(std::ostream &os, const Invoice &rhs);
};


std::string DisplayEnum(InvoiceType type);
#endif // INVOICE_H
