/*
	Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.
*/

#include <iostream>
#include "./classes/Sales_item.hpp"

int processBooksByISBN() {
	Sales_item book_sum, next_book;
	if (!(std::cin >> book_sum)) {
		std::cout << "No books detected." << std::endl;
		return -1;
	}
	std::cout << "ISBN | Copies Sold | Total Revenue | Average Price Per Sale" << std::endl;
	while (std::cin >> next_book) {
		if (book_sum.isbn() != next_book.isbn()) {
			std::cout << book_sum << std::endl;
			book_sum = next_book;
		} else {
			book_sum += next_book;
		}
	}
	std::cout << book_sum << std::endl;
	return 0;
}

int main() {
	return processBooksByISBN();
}