#include <iostream>

class Demo
{
private:
    /* data */
    int data;
public:
    Demo(/* args */) {
        this->data = 100;
        std::cout<< "Demo default\n";
    }
    ~Demo() {
        std::cout<<"Demo Destroyed\n";
    }
    Demo(const Demo & obj){
        std::cout<<"Copy Constructor\n";
    }

    int getData() const { return data; }
};

Demo Magic(){
    Demo d1;
    return d1;
}

int main(){
    Demo obj = Magic();
    
}