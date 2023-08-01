
#include "Employee.h"
#include "EmployeeGrade.h"
#include <list>

#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
using Container = std::list<Employee*>;

/*
    Find the average salary of all employees from a container of employees
*/

float AverageEmployeeSalary(Container& data);


/*
    Find the ID of the emoloyee with the highest salary form a container of employees
*/
std::string HighestSalaryEmployeeId(Container& data);


/*
    From a container of employees, return the count of all employees
    whose grade matches the values passed as an argument to the function
*/

int FindEmployeeWithMatchingGrade(Container& data, EmployeeGrade grade);


/*
    Return the name of an employee whose id is passed as a parameter to the function
*/

std::string FindEmployeeNameById(Container& data, std::string id);


/*
    Return the count of CAT_A  employees form a container of employees 
    where  CAT_A  is defined to be based on following expectations
        - salary should be over 40000
        - Grade should be FTE
*/

int CountCatAEmployee(Container& data);

bool isDataEmplty(Container& data);

// Employee** ReserveMemory(int count);

void createObject(Container & data);

#endif // FUNCTIONALITIES_H


