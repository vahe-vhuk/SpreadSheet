#ifndef SPREADSHEET_HPP_
#define SPREADSHEET_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <initializer_list>
#include "cell.hpp"

class SpreadSheet
{
	private:
		Cell** m_cells;
		size_t m_row;
		size_t m_colum;
	public:
		SpreadSheet() = delete;
		SpreadSheet(int,  int);
		~SpreadSheet();

		void add_row(size_t);
		void add_colum(size_t);

		size_t height();
		size_t weight();

		Cell& operator ()(int, int);

};

#include "spreadsheet.cpp"


#endif



