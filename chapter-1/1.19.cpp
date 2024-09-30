/*
    Revise the program you wrote for the exercises in page 13 that printed a range of numbers
    so that it handles input in which the first number is smaller than the second.
*/

#include <iostream>

void printRange(const int& start, const int& end) {
    int step = start < end ? 1 : -1;
    int current = start;
    while (current != end) {
        std::cout << current << std::endl;
        current += step;
    }
    std::cout << end << std::endl;
    std::cout << "--------" << std::endl;
    std::cout << "FINISH!" << std::endl;
}

int main() {
    std::cout << "Please enter two numbers: " << std::endl;
    int start, end;
    std::cin >> start >> end;

    if (start == end) {
        std::cout << "The start & end numbers (" << start 
                  << ") are the same..." << std::endl;
    } else if (start > end){ 
        int temp = start;
        start = end;
        end = temp;
    }
    printRange(start,end);
    return 0;
}