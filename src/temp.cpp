#include <iostream>

int main(){
    int a[] = {1, 2, 3};
    std::cout <<  sizeof(a) / sizeof(a[0]);
}