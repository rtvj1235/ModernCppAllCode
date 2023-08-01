
/*
     If we are having one argument constructor and we dont want that constructor 
     to type cast then we mark that constructor as explicit

*/


#include <iostream>

class Employee
{
private:
    /* data */
    int employeeId;
    std::string employeeName;
public:
    explicit Employee(int id):employeeId(id) {}     
    Employee(int id, std::string name):employeeId(id),employeeName(name){}
    Employee(const Employee & emp) = default;
    Employee(Employee && obj) = default;             //MOVE CONSTRUCTOR

    ~Employee() {
        std::cout<<"Employee wih id:"
                << this->employeeId
                <<" is destroyed\n";
        
    }
};


void magic(Employee emp){
    std::cout<<"Object Recieved"<<'\n';
}

int main(){
    /*
        If we do not write  explicit keyword in one argument constructor then this will work
        and it will automatically convert int 10 to employee object just beacause of 
        Employee(int id) and to avoid this type of conversion we write a explicit keyword
    */
    // magic(10);
    Employee e1(101,"aksahy");
    Employee e2(e1);
    Employee e3(Employee(121,"ajflj")) ;  // CALLING MOVE CONSTRUCTOR

    /*
        Suppose i want to move e1 to the new object e4 then we are going to write
        Employee e4(e1) -------> but this is going to call copy constructor but i want to move for
        that purpose we have std move function 
    */
   Employee e4 ( std::move(e1));


}