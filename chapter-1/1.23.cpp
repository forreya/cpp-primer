/*
	Write a program that reads several transactions and counts how many transactions occur for each ISBN.
*/

#include <iostream>
#include "./classes/Sales_item.hpp"

int countBooksByISBN() {
	Sales_item prev_book, next_book;
	int count;
	if (!(std::cin >> prev_book)) {
		std::cout << "No books detected." << std::endl;
		return -1;
	}
	count = 1;
	std::cout << "ISBN | Count" << std::endl;
	while (std::cin >> next_book) {
		if (prev_book.isbn() != next_book.isbn()) {
			std::cout << prev_book.isbn() << " : " << count << std::endl;
			count = 1;
			prev_book = next_book;
		} else {
			count ++;
		}
	}
	std::cout << prev_book.isbn() << " : " << count << std::endl;
	return 0;
}

int main() {
	return countBooksByISBN();
}