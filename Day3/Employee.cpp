#include "Employee.h"

/*
    Only one argument constructor that takes id as argument
*/

Employee::Employee(std::string empId):employeeId(empId){}


/*
    Parametrized constructor that takes 3 of the members
    id name and salary
*/
Employee::Employee(std::string empId, std::string empName, float empSalary)
    : employeeId(empId),employeeName(empName),employeeSalary(empSalary){}



/*

*/
Employee::Employee(std::string empId, std::string empName, float empSalary, 
EmployeeGrade empGrade, std::string emplocation, Skills empSkills)
    : Employee(empId,empName,empSalary)
{
    employeeGrade = empGrade;
    employLocation = emplocation;
    employeeSkills = empSkills;
}

std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "employeeId: " << rhs.employeeId
       << " employeeName: " << rhs.employeeName
       << " employeeSalary: " << rhs.employeeSalary
       << " employeeGrade: " << displayEnum(rhs.employeeGrade)
       << " employLocation: " << rhs.employLocation
       << " employeeSkills: " ;

       // ranged based for loop / for-each loop / iterative for loop

       //for every const string reference named as "skill"
       // in rhs.employeeSkills list

    for(const std::string & skill:rhs.employeeSkills){
        os<<skill<<" ";
    }

    return os;
}

float Employee::operator+(Employee &obj)
{
    return this->employeeSalary + obj.employeeSalary;

}


Employee::~Employee()
{
    std::cout<< "The Employee with ID:"
            << this->employeeId 
            << " Is destroyed\n";
}


std::string displayEnum(EmployeeGrade value)
{
    if(value == EmployeeGrade::FTE)
        return "FTE";
    else if(value == EmployeeGrade :: INTERN)
        return "INTERN";
    else
        return "NEW_RECRUIT";
}
