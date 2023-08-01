#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <memory>
#include <list>
#include <optional>

#include <variant>
#include "EngineeringStudent.h"
#include "CommerceStudent.h"

using EngineerPointer = std::shared_ptr<EngineeringStudent> ;
using CommercePointer = std::shared_ptr<CommerceStudent>;
using Type = std::variant<EngineerPointer, CommercePointer>;
using Container = std::list<Type>;


/*
    Create as many instancees of engineering student as required
*/

void CreateEngineeringStudentsObject(Container& data);

/*
    create as many instances of commercestudent as required
*/

void CreateCommerceStudentObjects(Container& data);

/*
    Function to find and return instances of both types of students whose
    CGPA is over 8.0f
*/

std::optional<Container> FindAbove8CGPAInstances(Container& data);

/*
    A function to find and return instances of both type of students whose
    scholarship amount is over 10000
*/

std::optional<Container> FindAbove10kScholarshipInstances(Container & data);

#endif // FUNCTIONALITIES_H
