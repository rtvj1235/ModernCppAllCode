#include "Functionalities.h"


/*
    Find the average salary of all employees from a container of employees
*/
float AverageEmployeeSalary(Container &data)
{
    if(isDataEmplty(data)){
        throw std::runtime_error("LIST IS EMPTY");
    }

    float sum=0.0f;
    for(auto &b : data){
        sum+=b->getEmployeeSalary();
    }
    return (float)(sum/data.size());
}

/*
    Find the ID of the emoloyee with the highest salary form a container of employees
*/

std::string HighestSalaryEmployeeId(Container &data)
{
    if(isDataEmplty(data)){
        throw std::runtime_error("LIST IS EMPTY");
    }
    float temp=0;
    std::string id="";
    for (Employee* emp : data){
        if(emp->getEmployeeSalary() > temp){
            temp = emp->getEmployeeSalary();
            id = emp->getEmployeeId();
        }
    }
    return id;
}


/*
    From a container of employees, return the count of all employees
    whose grade matches the values passed as an argument to the function
*/

int FindEmployeeWithMatchingGrade(Container &data, EmployeeGrade grade)
{
    if(isDataEmplty(data)){
        throw std::runtime_error("LIST IS EMPTY");
    }
    int count=0;
    for(Employee* emp : data){
        if(grade == emp->getEmpGrade()){
            count++;
        }
    }
    return count;
}


/*
    Return the name of an employee whose id is passed as a parameter to the function
*/

std::string FindEmployeeNameById(Container &data, std::string id)
{
    if(isDataEmplty(data)){
        throw std::runtime_error("LIST IS EMPTY");
    }
    for(Employee *emp : data){
        if(id == emp->getEmployeeId()){
            return emp->getEmployeeName();
        }
    }
    return 0;
}

/*
    Return the count of CAT_A  employees form a container of employees 
    where  CAT_A  is defined to be based on following expectations
        - salary should be over 40000
        - Grade should be FTE
*/


int CountCatAEmployee(Container &data)
{
    if(isDataEmplty(data)){
        throw std::runtime_error("LIST IS EMPTY");
    }
    int countCatA=0;
    for(Employee * emp : data){
        if((emp->getEmployeeSalary() > 40000 ) && (emp->getEmpGrade() == EmployeeGrade::FTE)){
            countCatA++;
        }
    }
    return countCatA;
}



bool isDataEmplty(Container &data)
{
    return data.empty();
}


void createObject(Container &data)
{
    data.emplace_back(new Employee("101","akshay",10000.0f,EmployeeGrade::FTE,"Pune",Skills{"Modern C++","Python"}));
    data.emplace_back(new Employee("102","ak",10000.0f,EmployeeGrade::INTERN,"Pune",Skills{"Modern C++","Python"}));
    data.emplace_back(new Employee("103","aslam",1000000.0f,EmployeeGrade::FTE,"Pune",Skills{"Modern C++","Python"}));
}
