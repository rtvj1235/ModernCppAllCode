
#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <iostream>
#include <list>
#include <memory>

using Pointer  = std::unique_ptr<int>;
using Container = std::list<Pointer>;
/*
    A function to create DUMMY data values and place them in the container
    Acquisition of memory should happend from heap
*/
void CreateDataValues(Container& data);

/*
    A function to find minimum number form a container of numbers
    
*/
int Minvalue(Container& data);

/*
    A function to find maximum number form a container of numbers
*/

int MaxValue(Container& data);


/*
    A function to find total size of a container of numbers
*/

int TotalSize(Container& data);

/*
    A function to Add a number to a container
*/

int AddNumber(Container& data, int number);

/*
    A function to find remove a number to a container
*/

void RemoveNumber(Container& data,int number);

void display(Container & data);


#endif // FUNCTIONALITIES_H


/*

End in stl containers means one beyond the index*
*/