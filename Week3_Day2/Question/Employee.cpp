#include "Employee.h"



std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "employeeId: " << rhs.employeeId
       << " employeeName: " << rhs.employeeName
       << " employeeSalary: " << rhs.employeeSalary;
    return os;
}


Employee::Employee(int id, std::string name, float salary)
:employeeId(id),employeeName(name),employeeSalary(salary)
{}

// Employee::~Employee()
// {
//     std::cout<<"EMPLOYEE DESTROYED\n";
// }

Employee Employee::operator+(const Employee &obj)
{
    Employee result;
    result.employeeSalary = this->employeeSalary + obj.employeeSalary;
    return result;
}

Employee Employee::operator-(const Employee &obj)
{
    Employee result;
    if(this->employeeSalary > obj.employeeSalary){
        result.employeeSalary = this->employeeSalary - obj.employeeSalary;
    }
    else{
        result.employeeSalary =  obj.employeeSalary - this->employeeSalary;
    }
    return result;
}
