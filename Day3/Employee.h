#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "EmployeeGrade.h"
#include <list>

using Skills = std::list<std::string>;

class Employee
{
private:
    std::string employeeId;
    std::string employeeName;
    float employeeSalary;
    EmployeeGrade employeeGrade;
    std::string employLocation;
    Skills employeeSkills;
    

public:
    Employee() = delete;

    Employee(const Employee &obj) = default;

    Employee(Employee &&obj) = default;

    explicit Employee(std::string empId);

    Employee(std::string empId, std::string empName, float empSalary);

    Employee(std::string empId, std::string empName,  float empSalary,
    EmployeeGrade empGrade,std::string emplocation,Skills empSkills );

    void display();
    
    float operator+(Employee &obj);

    std::string getEmployeeId() const { return employeeId; }
    void setEmployeeId(const std::string &employeeId_) { employeeId = employeeId_; }

    std::string getEmployeeName() const { return employeeName; }
    void setEmployeeName(const std::string &employeeName_) { employeeName = employeeName_; }

    EmployeeGrade getEmpGrade() const { return employeeGrade; }
    void setEmpGrade(const EmployeeGrade &empGrade_) { employeeGrade = empGrade_; }

    float getEmployeeSalary() const { return employeeSalary; }
    void setEmployeeSalary(float employeeSalary_) { employeeSalary = employeeSalary_; }

    std::string getEmployLocation() const { return employLocation; }
    void setEmployLocation(const std::string &employLocation_) { employLocation = employLocation_; }

    Skills getEmployeeSkills() const { return employeeSkills; }
    void setEmployeeSkills(const Skills &employeeSkills_) { employeeSkills = employeeSkills_; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

    // friend std::ostream &operator<<(std::ostream &os, const Employee &obj);


    ~Employee();
};

std::string displayEnum(EmployeeGrade value);

#endif // EMPLOYEE_H
