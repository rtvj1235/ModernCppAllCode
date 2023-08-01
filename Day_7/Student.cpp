#include <iostream>
#include "student.h"
class Library
{
private:
    /* data */
public:
    Library(/* args */) {}
     Library() {}
};

class Scholarship
{
private:
    /* data */
public:
    Scholarship(/* args */) {}
    ~Scholarship() {}
};

class Student
{
private:
    /* data */
    Scholarship& scholarshipStudent;
public:
    Student(Scholarship& scholarship) :
    scholarshipStudent(scholarship) {}
    
    ~Student() {}
};