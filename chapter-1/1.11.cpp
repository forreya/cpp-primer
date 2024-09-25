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
                  << ") are the same... " << std::endl;
    } else {
        printRange(start,end);
    }
    return 0;
}