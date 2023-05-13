#ifndef CELL_HPP_
#define CELL_HPP_

#include <iostream>
#include <string>
#include <exception>

class Cell
{
	private:
		std::string m_val;
	public:
		Cell();
		~Cell() = default;

		Cell(const Cell&);
		Cell(int);
		Cell(double);
		Cell(const std::string&);

		Cell operator =(const Cell&);
		Cell operator =(int);
		Cell operator =(double);
		Cell operator =(const std::string&);

		int to_int();
		double to_double();
		std::string to_string();
		
};

#include "cell.cpp"

#endif
