#ifndef COMMERCESTUDENT_H
#define COMMERCESTUDENT_H

#include <iostream>
#include <variant>
#include "CommerceStudentBranch.h"

class CommerceStudent
{
private:
    /* data */
    std::variant<int,std::string> commerceStudentId;
    CommerceStudentBranch commerceStudentBranch;
    float commerceStudentFees;
    float commerceStudentCGPA;

public:
    CommerceStudent(/* args */) = delete;
    CommerceStudent(const CommerceStudent& obj) = delete;
    CommerceStudent(CommerceStudent&& obj) = delete;
    CommerceStudent& operator= (CommerceStudent& obj) = delete;
    CommerceStudent(

        std::variant<int,std::string> commerceStudentId_,
        CommerceStudentBranch commerceStudentBranch_,
        float commerceStudentFees_,
        float commerceStudentCGPA_      
    );
    float CalculateScholarshipAmount();
    ~CommerceStudent();

    std::variant<int,std::string> getCommerceStudentId() const { return commerceStudentId; }
    void setCommerceStudentId(const std::variant<int,std::string> &commerceStudentId_) { commerceStudentId = commerceStudentId_; }

    CommerceStudentBranch getCommerceStudentBranch() const { return commerceStudentBranch; }
    void setCommerceStudentBranch(const CommerceStudentBranch &commerceStudentBranch_) { commerceStudentBranch = commerceStudentBranch_; }

    float getCommerceStudentFees() const { return commerceStudentFees; }
    void setCommerceStudentFees(float commerceStudentFees_) { commerceStudentFees = commerceStudentFees_; }

    float getStudentCGPA() const { return commerceStudentCGPA; }
    void setCommerceStudentCGPA(float commerceStudentCGPA_) { commerceStudentCGPA = commerceStudentCGPA_; }

    friend std::ostream &operator<<(std::ostream &os, const CommerceStudent &rhs);
};

std::string DisplayCommerceStudentBranch(CommerceStudentBranch type);
#endif // COMMERCESTUDENT_H
