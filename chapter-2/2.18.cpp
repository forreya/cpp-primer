/*
	Write code to change the value of a pointer. Write code to change the value to which the pointer points.
*/

#include <iostream>

int main() {
	int *p_random_int = nullptr;
	int random_int = 1207;
	int random_int_2 = 2809;
	p_random_int = &random_int;
	std::cout << "Currently pointing to " << *p_random_int << "." << std::endl;
	p_random_int = &random_int_2;
	std::cout << "Now pointing to " << *p_random_int << "." << std::endl;
}