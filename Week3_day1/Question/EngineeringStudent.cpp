#include "EngineeringStudent.h"

EngineeringStudent::EngineeringStudent(
    std::variant<int, std::string> engineeringStudentId_, EngineeringStudentBranch engineeringStudentBranch_, 
    float engineeringStudentFees_, float engineeringStudentCGPA_
    ):engineeringStudentId(engineeringStudentId_),engineeringStudentBranch(engineeringStudentBranch_),
    engineeringStudentFees(engineeringStudentFees_)
{
    if(engineeringStudentCGPA_ <=10.0f && engineeringStudentCGPA_ >= 0.0f ){
        this->engineeringStudentCGPA = engineeringStudentCGPA_;
    }
    else{
        throw std::runtime_error("INVALID CGPA");
    }
}

EngineeringStudent::~EngineeringStudent()
{
    std::cout<<"ENGINEER STUDENT WITH ID:";
    std::visit([](auto && val){std::cout<<val;},this->engineeringStudentId);
    std::cout<<"IS DELETED\n";
}


// USE OPTIONAL WHEN THERE IS EXACTLY ONE REASON WHY A VALUE MAY OR MAY NOT EXIST
// THIS ONE REASON SHOULD BE WELL KNOWN TO THE DESIGNER OF THE FUNCTION AS WELL AS USER

float EngineeringStudent::CalculateScholarshipAmount()
{
    if(this->engineeringStudentCGPA > 8.0f){
        return 0.4f * this->engineeringStudentFees;
    }
    if(this->engineeringStudentCGPA > 6.0f && this->engineeringStudentCGPA <= 8.0f){
        return 0.1f * this->engineeringStudentFees;
    }
    return 0.0f;
}



std::ostream &operator<<(std::ostream &os, const EngineeringStudent &rhs) {
    os << "engineeringStudentId: ";
    std::visit([&](auto&& val){os << val;},rhs.engineeringStudentId);

    os<< " engineeringStudentBranch: " << DisplayEngineeringStudentBranch(rhs.engineeringStudentBranch)
       << " engineeringStudentFees: " << rhs.engineeringStudentFees
       << " engineeringStudentCGPA: " << rhs.engineeringStudentCGPA;
    return os;
}

std::string DisplayEngineeringStudentBranch(EngineeringStudentBranch type)
{
    if(type == EngineeringStudentBranch::CIVIL) {return "CIVIL";}
    else if(type == EngineeringStudentBranch::CS) {return "CS";}
    else if(type == EngineeringStudentBranch::ECE) {return "ECE";}
    else if(type == EngineeringStudentBranch::ELECTRONICS){return "ELECTRONICS";}
    else if(type == EngineeringStudentBranch::IT){return "IT";}
    else{
        return "MECH";
    }
}
