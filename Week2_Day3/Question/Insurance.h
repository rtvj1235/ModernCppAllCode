#ifndef INSURANCE_H
#define INSURANCE_H

#include "InsuranceType.h"
#include <iostream>
class Insurance
{
private:
    /* data */
    std::string insuranceId;
    float insuranceAmount;
    InsuranceType insuranceType;

public:
    Insurance(/* args */) = delete;
    Insurance(const Insurance &obj) = default;
    Insurance(Insurance &&obj) = delete;
    ~Insurance();
    Insurance(std::string id, float amount, InsuranceType type);

    std::string getInsuranceId() const { return insuranceId; }
    void setInsuranceId(const std::string &insuranceId_) { insuranceId = insuranceId_; }

    float getInsuranceAmount() const { return insuranceAmount; }
    void setInsuranceAmount(float insuranceAmount_) { insuranceAmount = insuranceAmount_; }

    InsuranceType getInsuranceType() const { return insuranceType; }
    void setInsuranceType(const InsuranceType &insuranceType_) { insuranceType = insuranceType_; }

    friend std::ostream &operator<<(std::ostream &os, const Insurance &rhs);
};

std::string DisplayInsuranceType(InsuranceType type);

#endif // INSURANCE_H
