/*
	Use the Sales_item class to write a program that reads a set of book sales transactions,
	writing each transaction to the standard output.
*/

#include <iostream>
#include "./classes/Sales_item.hpp"

void outputBookSales(Sales_item book) {
	/*
		Outputs ISBN, number of copies sold, total revenue, average sales price
	*/
	std::cout << book << std::endl;
}

int main() {
	std::cout << "ISBN | Copies Sold | Total Revenue | Average Price Per Sale" << std::endl;
	Sales_item book;
	while (std::cin >> book) {
		outputBookSales(book);
	}
	return 0;
}