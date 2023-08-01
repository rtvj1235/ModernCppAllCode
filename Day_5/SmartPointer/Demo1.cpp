#include <iostream>
#include <memory> //Library for smartPointers

// We need to mention to whom smart pointer in pointing in <> this brackets in this it is int pointer
using Pointer = std::unique_ptr<int>; 
/*
    Here we should always pass by reference instead of call by value 
    Cause we cannot copy unique pointer since its copy constructor is disabled
*/
void MagicUltraProMax(Pointer& ptr)          
{
    std::cout << *ptr << "\n";
}
void MoreMagic(Pointer& ptr)
{
    MagicUltraProMax(ptr);
}

void Magic(Pointer& ptr)
{
    MoreMagic(ptr);
}

int main()
{
    /*
        Ptr is unique_ptr to an integer
        It is constructed (made) by storing  value 10 on the heap
    */
    /*
         Syntax for making smart Pointers instead of new we use make_unique<>
         here we are pointing ptr to integer 10 that
         ptr = make_unique<int>(10)
    */
    Pointer ptr = std::make_unique<int>(10);
    Magic(ptr);
}