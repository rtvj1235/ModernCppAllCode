#include <iostream>

class Practice
{
private:
    /* data */
    int x;
    int y;
public:
    Practice() {
        x = y =0;
    }
    Practice(int x , int y){
        this->x = x;
        this->y = y;
    }
    ~Practice() {}
    void display(){std::cout<<x<<" "<<y<<"\n";};
};

int main(){
    Practice P1(2,3);
    Practice P2 = P1;
    P2.display();
    
}


/*
#include <iostream>

int main(){
    int myint = 1;
    char mychar = 'A';
    double mydouble = 456.343;
    bool mybool = true;
    myint = mychar;
    mydouble = myint;
    mychar = mybool;
    std::cout<<mychar<<"\n";
}

*/

