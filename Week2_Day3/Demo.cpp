#include <iostream>
#include <thread>
#include <functional>

using namespace std::placeholders;
/*
    One function can become one thread provided it has to
    independent form another
    A thread is seires of instructions and data required to complete those instructions
*/

int temp2(int n){
    // std::cout<<"hello world\n";
    return n+2;
}


void square(int number,int number2,int temp){
    // return number * number2;
    int b = temp2(number);
    std::cout<<b<<"\n";
    std::cout<<number<<"\n";
    std::cout<<number2<<"\n";
    std::cout<<temp<<"\n";
}

int cube(int number){
    return number * number * number;
}

int main(){
    // square(10);
    // cube(10);
    auto fn = std::bind(&square,_2,_2,_1);
    fn(10,2,0,0,6777);
    auto f2 = std::thread(fn,1,10,2,0,0,0);
    // f2.join();
    // auto lam = [](auto a , auto b,auto){
    //     square(b,a,1000);
    // };
    // lam(10,2,1);
    // auto f = std::thread(&square,1,2,3);
    // auto f2 = std::thread(&temp2,10);
    f2.join();

}

// int square(int number) {
//     return number * number;
// }

// int cube(int number) {
//     return number * number * number;
// }

// int main() {

//     std::thread squareThread([]() {
//         int result = square(10);
//         std::cout << "Square result: " << result << std::endl;
//     });

//     std::thread cubeThread([]() {
//         int result = cube(10);
//         std::cout << "Cube result: " << result << std::endl;
//     });

//     squareThread.join();
//     cubeThread.join();

//     return 0;
// }

// // #include <iostream>
// // #include <list>

// class temp
// {
//     int t;

// public:
//     temp() = default;
//     temp(int t_) : t(t_) {}
//     virtual ~temp()
//     {
//         std::cout << "hello";
//     }
//     void display()
//     {
//         std::cout << "hello wrold\n";
//     }
// };

// void magic(temp obj)
// {
//     obj.display();
// }
// class demo : public temp
// {
// public:
//     ~demo()
//     {
//         std::cout << "demo destroyed";
//     }
// };

// int main()
// {
//     temp *t1 = new demo();
//     // delete t1;
//     // temp *t2 = new temp(std::move(*t1));
//     // magic(10);
//     std::list<temp> data{*t1};
    
// }