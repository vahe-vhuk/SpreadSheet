#include <iostream>
#include "spreadsheet.hpp"

int main()
{
	SpreadSheet table(4, 5);

	table(2, 2) = 5;
	table(1, 1) = 4.4;
	table(0, 0) = "hy";

	std::cout << table << "\n";

	table.add_row(3);


	table(6, 1) = "3";

	std::cout << table << "\n";

	table.add_colum(3);

	table(6, 7) = 0;

	std::cout << table;

	return 0;
}
