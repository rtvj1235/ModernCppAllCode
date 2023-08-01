#include <iostream>
#include <memory>
#include <list>

class Employee
{
private:
    int employeeId;
    std::string employeeName;

public:
    Employee() = default;
    Employee(int i, std::string name) : employeeId(i), employeeName(name){};
    ~Employee()
    {
        std::cout << "Employee with Id "
                  << this->employeeId
                  << " id destroyed\n";
    }
};

/*
    Container MEANS : a std list of items where each item is a std :: unique_ptr to an employee
*/

using Container = std::list<std::unique_ptr<Employee>>;

void CreateObjects(Container &data)
{
    std::unique_ptr<Employee> e1 = std::make_unique<Employee>(104, "aslam");

    data.emplace_back(
        std::move(e1));

    /*
        Make_unique working
            step 1 - construct a new value of T type on the hap
            step 2 - Store a pointer to its location on the heap
            step 3 - construct a new smart pointer (unique_ptr)
            step 4 - initialize it by using the pointer form step 2
    */
    data.emplace_back(std::make_unique<Employee>(103, "kuldeep"));
}

int main()
{
    Container data;
    CreateObjects(data);
}

/*
    std::unique_ptr ptr1 = ptr2  // this is not allowed
    Even call by copy wihtout reference is not allowed
*/