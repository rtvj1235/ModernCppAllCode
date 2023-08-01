// Keyboard Shortcuts

/*
    crtl + shift + o for searching something like Name employee in code
    crtl + f for searching comments and all
    ctrl + k + o for opening folder or file
*/

/*
    name;
    id
    salary
    Add 2 employee to get combined salary
    print employee int the screen in some specific format
    I want to calculate Tax for every empliyee as 10% of their salary
    Delete the employee by printed "Employee with ID:" << employeeID << " Id deleted\n";
    intitialization with name and id is allowed
    Initialization with name id and salary is allowed
*/

#include <iostream>
class Employee
{
private:
    std::string employeeName;
    int employeeID;
    float employeeSalay;

public:
    Employee() {}
    Employee(std::string employeeName, int employeeID, float employeeSalary){
        this->employeeID=  employeeID;
        this->employeeName =  employeeName;
        this->employeeSalay =  employeeSalary;
    }

    Employee(std::string employeeName, int employeeID){
        this->employeeName = employeeName;
        this->employeeID =  employeeID;
    }
    float CalcualteTax()
    {
        return 0.1f * this->employeeSalay;
    }
    ~Employee()
    {
        std::cout << "Employee With Id:"
                  << this->employeeID << "is destroyed\n"
                  << std::endl;
    }
    float operator+(const Employee &E2)
    {
        return this->employeeSalay + E2.employeeSalay;
    }
    friend  std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "employeeName: " << rhs.employeeName
           << " employeeID: " << rhs.employeeID
           << " employeeSalay: " << rhs.employeeSalay;
        return os;
    }
    

};

/*
    Take an array of 3 pointers
    Create objects on heap and store there address in the array
*/

void CreateObjects(Employee* arr[3])
{
    arr[0] = new Employee("Akshay",1011,10000.01f);
    arr[1] = new Employee("Rohan", 1012, 109892.09f);
    arr[2] = new Employee("Kuldeep", 1013, 34000000.0f);
}
void calculateEmployeeTax(Employee* arr[3]){
    for(int i=0;i<3;i++){
        std::cout<< (*(arr+i))->CalcualteTax()<<"\n";
    }
}
int main()
{
    Employee* arr[3];
    CreateObjects(arr);
    calculateEmployeeTax(arr);
    // int *b = new int;
    // int * a= (int*)malloc(sizeof(int));

}