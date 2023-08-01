#include <iostream>

void magic( int && n2)
{

}

int main()
{
    int n =10;
    magic(std::move(n)); // int && n2 = n;
    std::cout<<n ;       // Undefined behaviout !!!

    int *n1 = (int*)malloc(4);
    magic(std::move(*n1));
    std::cout<<"\n"<< *n1;

}

/*

    Lvalues & Rvalues
    move semantics & copy semantcis
    std::move : convert something to a rvalue
    WHAT DOES CONSTRUCTOR RETURNS ?
    what does explicit used for ?
    why does const lvalue reference to T accepts R value of type T?
    Why does rvalue reference to type T actually bind to a rvalue ?
*/