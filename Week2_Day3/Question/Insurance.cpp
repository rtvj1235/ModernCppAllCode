#include "Insurance.h"


std::ostream &operator<<(std::ostream &os, const Insurance &rhs) {
    os << "insuranceId: " << rhs.insuranceId
       << " insuranceAmount: " << rhs.insuranceAmount
       << " insuranceType: " << DisplayInsuranceType(rhs.insuranceType);
    return os;
}

std::string DisplayInsuranceType(InsuranceType type)
{
    if(type == InsuranceType::REGULAR) return "REGULAR";
    else{
        return "ZERO_DEBT";
    }
}

Insurance::~Insurance()
{
    std::cout<<"Insurance Deleted"<<"\n";
}


Insurance::Insurance(std::string id, float amount, InsuranceType type)
 :insuranceId(id),insuranceAmount(amount), insuranceType(type)
 {}
