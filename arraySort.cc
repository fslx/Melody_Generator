#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdio>


int my_array[3] = {1,2,3};
std::string my_string_array[4] = {"Hello", "From", "C++", "Array"};

void sortArray() {
    for(int i = 0; i < 5; i++) {
        std::cout << my_string_array[i] << std::endl;
    }
}

int main() {
    std::cout << my_array[1] << std::endl; // output: 2
    std::cout << my_string_array[2] << std::endl;     // output: C++
    sortArray(); // output: Hello From C++ Array
    return 0;
}