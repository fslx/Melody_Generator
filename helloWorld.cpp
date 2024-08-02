#include <stdio.h>
#include <iostream>
#include <string>

// testing my own setup of the g++ compiler as I ran into issues with using .cc and gcc
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string hello = "Hello there!";
    std::cout << hello << std::endl;
    int x;
    x = 1;
    std::cout << x << std::endl;
    return 0;
}
