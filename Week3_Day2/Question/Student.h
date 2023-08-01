#include <iostream>
class Student
{
private:
    /* data */
    int studentId;
    std::string studentName;
    float studentFees;
public:
    Student(/* args */) = default;
    Student(int id,std::string name,float fees);
    ~Student() {};


    std::string getStudentName() const { return studentName; }
    void setStudentName(const std::string &studentName_) { studentName = studentName_; }

    float getStudentFees() const { return studentFees; }
    void setStudentFees(float studentFees_) { studentFees = studentFees_; }

    int getStudentId() const { return studentId; }
    void setStudentId(int studentId_) { studentId = studentId_; }

    friend std::ostream &operator<<(std::ostream &os, const Student &rhs);
    Student operator+(const Student& obj);
    Student operator-(const Student& obj);
    
};