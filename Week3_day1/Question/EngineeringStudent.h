#ifndef ENGINEERINGSTUDENT_H
#define ENGINEERINGSTUDENT_H

#include <iostream>
#include <variant>
#include "EngineeringStudentBranch.h"


class EngineeringStudent
{
private:
    /* data */
    std::variant<int,std::string> engineeringStudentId;
    EngineeringStudentBranch engineeringStudentBranch;
    float engineeringStudentFees;
    float engineeringStudentCGPA;
public:
    EngineeringStudent(/* args */) = delete;
    EngineeringStudent(const EngineeringStudent& obj) = delete;
    EngineeringStudent(EngineeringStudent&& obj) = delete;
    EngineeringStudent& operator=(EngineeringStudent& obj) = delete;
    EngineeringStudent(
        std::variant<int, std::string> engineeringStudentId_,
        EngineeringStudentBranch engineeringStudentBranch_,
        float engineeringStudentFees_, float engineeringStudentCGPA_
        );
    
    ~EngineeringStudent();
    float CalculateScholarshipAmount();


    std::variant<int,std::string> getEngineeringStudentId() const { return engineeringStudentId; }
    void setEngineeringStudentId(const std::variant<int,std::string> &engineeringStudentId_) { engineeringStudentId = engineeringStudentId_; }

    EngineeringStudentBranch getEngineeringStudentBranch() const { return engineeringStudentBranch; }
    void setEngineeringStudentBranch(const EngineeringStudentBranch &engineeringStudentBranch_) { engineeringStudentBranch = engineeringStudentBranch_; }

    float getEngineeringStudentFees() const { return engineeringStudentFees; }
    void setEngineeringStudentFees(float engineeringStudentFees_) { engineeringStudentFees = engineeringStudentFees_; }

    float getStudentCGPA() const { return engineeringStudentCGPA; }
    void setEngineeringStudentCGPA(float engineeringStudentCGPA_) { engineeringStudentCGPA = engineeringStudentCGPA_; }

    friend std::ostream &operator<<(std::ostream &os, const EngineeringStudent &rhs);
};

std::string DisplayEngineeringStudentBranch(EngineeringStudentBranch type);

#endif // ENGINEERINGSTUDENT_H
