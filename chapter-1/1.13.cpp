/*
    Rewrite the exercises from page 13 using for loops.
*/

#include <iostream>

constexpr int START = 1;
constexpr int END = 10;

int sumRange(const int& start, const int& end) {
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    std::cout << "Sum of " << START << " to " 
              << END << " inclusive is " 
              << sumRange(START,END) << std::endl;
    return 0;
}
