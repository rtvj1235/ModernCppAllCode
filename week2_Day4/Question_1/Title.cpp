#include <iostream>


void magic(int n){
    std::cout<<n1;
    std::cout<<"Adress of n(magic):"<<&n<<"\n"
}
int main(){
    // auto fn = [](int*arr){
    //     int max = arr[0];
    //     for(int i=0;i<5;i++){
    //         if(max<arr[i])
    //             max = arr[i];
    //     }
    //     return max;
    // };
    // int arr[5] = {1,2,3,4,5};
    // std::cout<<fn(arr);
    // auto fn = [](int a){return a;};
    int(*fn)(int) = [](int a){return a;};

}

/*
    std::ref

    std::reference_wrapper : 
*/