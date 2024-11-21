/*
	Write your own version of the Sales_data.h header and use it to rewrite the exercise from § 2.6.2 (p. 76).
*/

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>
	struct Sales_data {
		std::string isbn;
		unsigned units_sold = 0;
		double revenue = 0;
	};
#endif