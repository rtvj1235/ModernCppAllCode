#include <iostream>
#include <functional>
#include <optional>
#include <memory>
#include <variant>

// class A
// {
// private:
//     /* data */
// public:
//     A(/* args */) = default;
//     virtual ~A() {
//         std::cout<<"A Destroyed\n";
//     }
//     virtual void Display() = 0;
// };

// class B : public A
// {
// private:
//     /* data */

// public:
//     B(/* args */) = default;
//     void Display() override{
//         std::cout<<"B display Function\n";
//     }
//     ~B() {
//         std::cout<<"B destroyed\n";
//     }
// };

// class C : public A
// {
// private:
//     /* data */
// public:
//     C(/* args */) = default;
//     void Display() override{
//         std::cout<<"C display Function\n";
//     }
//     ~C() {
//         std::cout<<"C destroyed\n";
//     }
// };

// int main(){
//     A * obj = new B();
//     A* obj1 = new C();
//     obj->Display();
//     obj1->Display();
//     delete obj1;
//     delete obj;

// }

/*
    same logic using varient and visit
    Visit takes two parameters first one is callable it should be lambda
    and 2nd as varient

    we used template for unbounded set of types --> when the number of types
    that we want to use are not fixed but when the variation are fixed in the numbers
    we used varient
*/

class B
{
private:
    /* data */

public:
    B(/* args */) = default;
    void Display()
    {
        std::cout << "B display Function\n";
    }
    ~B()
    {
        std::cout << "B destroyed\n";
    }
};

class C
{
private:
    /* data */
public:
    C(/* args */) = default;
    void Display()
    {
        std::cout << "C display Function\n";
    }
    ~C()
    {
        std::cout << "C destroyed\n";
    }
};


using Pointer = std::unique_ptr<B>;
using PointerC = std::unique_ptr<C>;

int main()
{
    std::variant<Pointer, PointerC> obj;
    obj = std::make_unique<B>();
    /*
        TO call functions on varient we use VISIT
    */
    std::visit([](auto&& val)
               { val->Display(); },
               obj);

    obj = std::make_unique<C>();

    /*
         Visit for C
    */
    std::visit([](auto&& val)
               { val->Display(); },
               obj);
}