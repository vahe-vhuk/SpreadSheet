#ifndef CELL_CPP_
#define CELL_CPP_

#include "cell.hpp"

Cell::Cell()
{
	m_val = "_";
}

Cell::Cell(const Cell& cl)
{
	m_val = cl.m_val;
}

Cell::Cell(int val)
{
	m_val = std::to_string(val);
}

Cell::Cell(double val)
{
	m_val = std::to_string(val);
}

Cell::Cell(const std::string& val)
{
	m_val = val;
}

Cell
Cell::operator =(const Cell& cl)
{
	if (this != &cl) {
		m_val = cl.m_val;
	}
	return *this;
}

Cell
Cell::operator =(int val)
{
	m_val = std::to_string(val);
	return *this;
}

Cell
Cell::operator =(double val)
{
	m_val = std::to_string(val);
	return *this;
}

Cell
Cell::operator =(const std::string& val)
{
	if (&m_val != &val) {
		m_val = val;
	}
	return *this;
}

int
Cell::to_int() {
	int res = 0;
	try {
		res = std::stoi(m_val);
	}
	catch (std::exception& e) {};
	return res;
}

double
Cell::to_double()
{
	double res = 0;
	try {
		res = std::stod(m_val);
	}
	catch (std::exception& e) {};
	return res;
}

std::string
Cell::to_string()
{
	return m_val;
}


#endif
