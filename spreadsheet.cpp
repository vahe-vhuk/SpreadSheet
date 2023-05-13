#ifndef SPREADSHEET_CPP_
#define SPREADSHEET_CPP_

SpreadSheet::SpreadSheet(int row,  int colum)
{
	if (row < 1 || colum < 1) {
		throw std::invalid_argument("Spreadsheet must have minimum size fo 1x1");
	}
	m_row = row;
	m_colum = colum;

	m_cells = new Cell*[row];
	for (size_t i = 0; i < row; ++i) {
		m_cells[i] = new Cell[colum];
	}
}

SpreadSheet::~SpreadSheet()
{
	for (size_t i = 0; i < m_row; ++i) {
		delete[] m_cells[i];
	}
	delete[] m_cells;
}

Cell&
SpreadSheet::operator ()(int i,  int j)
{
	if (i < 0 || i > m_row || j < 0 || j > m_colum) {
		throw std::invalid_argument("index out of range");
	}
	return (Cell&)m_cells[i][j];
}


void 
SpreadSheet::add_row(size_t val)
{
	if (val < 1) {
		throw std::invalid_argument("uncorrect arguments to increment size of rows");
	}
	Cell** tmp = new Cell*[m_row + val];
	for (size_t i = 0; i < m_row + val; ++i) {
		if (i < m_row) {
			tmp[i] = m_cells[i];
		}
		else {
			tmp[i] = new Cell[m_colum];
		}
	}
	delete[] m_cells;
	m_cells = tmp;
	m_row = m_row + val;
}


void
SpreadSheet::add_colum(size_t val)
{
	if (val < 1) {
		throw std::invalid_argument("uncorrect arguments to increment size of colums");
	}
	for (size_t i = 0; i < m_row; ++i) {
		Cell* tmp = new Cell[m_colum+val];
		for (size_t j = 0; j < m_colum + val; ++j) {
			if (j < m_colum) {
				tmp[j] = m_cells[i][j];
			}
			else {
				tmp[j] = Cell();	
			}
		}
		delete[] m_cells[i];
		m_cells[i] = tmp;
	}
		m_colum += val;
}

size_t
SpreadSheet::height()
{
	return m_row;
}

size_t
SpreadSheet::weight()
{
	return m_colum;
}


std::ostream&
operator <<(std::ostream& out, SpreadSheet& tab)
{
	size_t row = tab.height();
	size_t col = tab.weight();
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < col; ++j) {
			std::string res = tab(i, j).to_string();
			std::cout << res << " ";
		}
		std::cout << "\n";
	}
	return out;
}






#endif
