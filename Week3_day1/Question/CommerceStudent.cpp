#include "CommerceStudent.h"

CommerceStudent::CommerceStudent(
    std::variant<int, std::string> commerceStudentId_, CommerceStudentBranch commerceStudentBranch_, 
    float commerceStudentFees_, float commerceStudentCGPA_)
    :commerceStudentId(commerceStudentId_), commerceStudentBranch(commerceStudentBranch_),
    commerceStudentFees(commerceStudentFees_)
{
    if(commerceStudentCGPA_ >= 0.0f && commerceStudentCGPA_ <= 10.0f){
        this->commerceStudentCGPA = commerceStudentCGPA_;
    }
    else{
        throw std::runtime_error("INVALID CGPA");
    }

}

float CommerceStudent::CalculateScholarshipAmount()
{
    if(this->commerceStudentCGPA > 8.0f && this->commerceStudentCGPA<= 10.0f){
        return 0.3f * this->commerceStudentFees;
    }
    else if(this->commerceStudentCGPA >=6 && this->commerceStudentCGPA <= 8.0f){
        return 0.2f * this->commerceStudentFees;
    }
    else if((this->commerceStudentCGPA < 6.0f && this->commerceStudentCGPA>=0.0f ) && this->commerceStudentFees >50000){
        return 0.1f * this->commerceStudentFees;
    }
    return 0.0f;
}

CommerceStudent::~CommerceStudent()
{
    std::cout<<"COMMERCE STUDENT WITH ID:";
    std::visit([](auto && val){std::cout<<val<<"\n";},this->commerceStudentId);
    std::cout<<"IS DESTROYED\n";
}

std::ostream &operator<<(std::ostream &os, const CommerceStudent &rhs) {
    os << "commerceStudentId: ";
    std::visit([&](auto && val){ os <<val ;},rhs.commerceStudentId);
       os<< " commerceStudentBranch: " << DisplayCommerceStudentBranch(rhs.commerceStudentBranch)
       << " commerceStudentFees: " << rhs.commerceStudentFees
       << " commerceStudentCGPA: " << rhs.commerceStudentCGPA;
    return os;
}

std::string DisplayCommerceStudentBranch(CommerceStudentBranch type)
{
    if(type == CommerceStudentBranch::BANKING) {return "BANKING";}
    else if(type == CommerceStudentBranch::CA) {return "CA";}
    else if(type == CommerceStudentBranch::CS) {return "CS";}
    else if(type == CommerceStudentBranch::FINANCE){return "FINANCE";}
    else{
        return "MM";
    }
}
