#include "Student.h"

Student::Student(int id, std::string name, float fees)
:studentId(id),studentName(name),studentFees(fees)
{}

// Student::~Student()
// {
//     std::cout<<"STUDENT DESTOYED\n";
// }

Student Student::operator+(const Student &obj)
{
    Student result;
    result.studentFees = this->studentFees + obj.studentFees;
    return result;
}

Student Student::operator-(const Student &obj)
{
    Student result;
    if(this->studentFees > obj.studentFees){
        result.studentFees = this->studentFees - obj.studentFees;
    }
    else{
        result.studentFees = obj.studentFees - this->studentFees;
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const Student &rhs) {
    os << "studentId: " << rhs.studentId
       << " studentName: " << rhs.studentName
       << " studentFees: " << rhs.studentFees;
    return os;
}

