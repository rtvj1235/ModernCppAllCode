#include "Employee.h"
#include "Functionalities.h"

int main(){
    Container data;
    createObject(data);
    float avg = AverageEmployeeSalary(data);
    std::cout<<avg<<"\n";
    std::string temp = HighestSalaryEmployeeId(data);
    std::cout<<temp<<"\n";
    int emp = FindEmployeeWithMatchingGrade(data,EmployeeGrade::FTE);
    std::cout<<emp<<"\n";
}
