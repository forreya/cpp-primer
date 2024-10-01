/*
	Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.
*/

#include <iostream>
#include "./classes/Sales_item.hpp"

int sumTwoBooks(Sales_item book1, Sales_item book2) {
	if (book1.isbn() != book2.isbn()) {
		std::cout << "ISBNs of the two books aren't the same." << std::endl;
		return -1;
	}
	std::cout << "ISBN | Copies Sold | Total Revenue | Average Price Per Sale\n"
			<< book1 + book2
			<< std::endl;
	return 0;
}

int main() {
	Sales_item book1, book2;
	std::cin >> book1 >> book2;
	return sumTwoBooks(book1, book2);
}