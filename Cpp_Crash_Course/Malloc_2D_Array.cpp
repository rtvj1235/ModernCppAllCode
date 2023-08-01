#include<iostream>


int **AllocateMemory(int location){
    int ** arr =(int**) malloc(location * sizeof(int *));
    return arr;
}

void fillValueToArray(int **arr,int locations){
    for(int i=0;i<locations;i++){
        for(int j=0;j<locations;j++){
            *(*(arr+i)+j)= i+1;
        }
    }
}
void display(int **arr,int location){
    for(int i=0;i<location;i++){
        for(int j=0;j<location;j++){
            std::cout<< *(*(arr+i)+j)<<"\t";
        }
        std::cout<<"\n";
    }
}

void allocateArraytoArray(int **arr,int location){
    for(int i=0;i<location;i++){
        *(arr+i) = (int*)malloc(3 * sizeof(int));
    }
}

// void FreeMemory(int location, int **arr){
//     for(int i=0;i<location;i++){
//         free(*(arr+i));
//     }
//     free(arr);
// }


int main()
{
    int ** arr = AllocateMemory(5);
    allocateArraytoArray(arr,5);
    fillValueToArray(arr,5);

    display(arr,5);
    // FreeMemory();

}