#include <iostream>

class Employee
{
private:
    /* data */
    int employeeId;
    std::string employeeName;
    float employeeSalary;
public:
    Employee(/* args */) = default;
    Employee(int id,std::string name,float salary);
    ~Employee(){};

    float getEmployeeSalary() const { return employeeSalary; }
    void setEmployeeSalary(float employeeSalary_) { employeeSalary = employeeSalary_; }

    std::string getEmployeeName() const { return employeeName; }
    void setEmployeeName(const std::string &employeeName_) { employeeName = employeeName_; }

    int getEmployeeId() const { return employeeId; }
    void setEmployeeId(int employeeId_) { employeeId = employeeId_; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
    Employee operator+(const Employee& obj);
    Employee operator-(const Employee& obj);
};