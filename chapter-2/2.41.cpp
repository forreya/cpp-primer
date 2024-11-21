/*
	Use your Sales_data class to rewrite the exercises in § 1.5.1 (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your Sales_data class in the same file as your main function.
*/

#include <iostream>
#include <string>

struct Sales_data {
	std::string isbn;
	unsigned units_sold = 0;
	double revenue = 0;
};

// For page 22 and 24
//int main() {
//	Sales_data book1;
//	std::cout << "Add data for book 1: ";
//	std::cin >> book1.isbn;
//	std::cin >> book1.units_sold;
//	std::cin >> book1.revenue;
//	std::cout << "Book 1 Data: " << book1.isbn << " "
//		<< book1.units_sold << " "
//		<< book1.revenue << " " << std::endl;
	
//	Sales_data book2;
//	std::cout << "Add data for book 2: ";
//	std::cin >> book2.isbn;
//	std::cin >> book2.units_sold;
//	std::cin >> book2.revenue;
//	std::cout << "Book 2 Data: " << book2.isbn << " "
//		<< book2.units_sold << " "
//		<< book2.revenue << " " << std::endl;

//	if (book1.isbn == book2.isbn) {
//		std::cout << "Okay they have the same ISBN..." << std::endl;
//	} else {
//		std::cout << "They are different books, can't add them up- sorry!" << std::endl;
//		return -1;
//	}

//	std::cout << "Adding up the stats..." << std::endl;
//	unsigned total_revenue = book1.revenue + book2.revenue;
//	unsigned total_units_sold = book1.units_sold + book2.units_sold;
//	std::cout << "Total Revenue: " << total_revenue << std::endl;
//	std::cout << "Total Units Sold: " << total_units_sold << std::endl;
//	std::cout << "Average Price: " << total_revenue / total_units_sold << std::endl;
//	return 0;
//}

// For page 25
int main() {
	unsigned total_revenue = 0;
	std::string last_isbn = "";
	Sales_data curr_data;
	while (std::cin >> curr_data.isbn >> curr_data.units_sold >> curr_data.revenue) {
		if (last_isbn == "" || curr_data.isbn == last_isbn) {
			total_revenue += curr_data.revenue;
			last_isbn = curr_data.isbn;
		} else {
			std::cout << "Total Revenue For ISBN " << last_isbn << ": " << total_revenue << std::endl;
			total_revenue = curr_data.revenue;
			last_isbn = curr_data.isbn;
		}
	}
	std::cout << "Total Revenue For ISBN " << last_isbn << ": " << total_revenue << std::endl;
}