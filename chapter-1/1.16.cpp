/*
    Write your own version of a program that prints the sum of a set of integers read from cin.
*/

#include <iostream>

int main() {
    int sum = 0, val = 0;
    while (std::cin >> val) {
        sum += val;
    }
    std::cout << "The sum is " << sum << std::endl;
    return 0;
}