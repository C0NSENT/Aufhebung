//
// Created by consent_ on 07-Apr-25.
//

#include "table_output.h"

#include <iomanip>
#include <stdexcept>

Table_output::cell::cell(const std::string& cell_content, const size_t& data_length)
	: content(cell_content)
	, length(data_length) {}

//*****************************************************************
//	ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
//*****************************************************************

size_t Table_output::strlen(const std::string &s)
{
	size_t length{0};
	for (size_t i = 0; i < s.length();) {
		if (const unsigned char c = s.at(i); c < 0x80) {
			i += 1;
		} else if (( c & 0xE0) == 0xC0 ) {
			i += 2;
		} else if (( c & 0xF0) == 0xE0 ) {
			i += 3;
		} else if (( c & 0xF8) == 0xF0 ) {
			i += 4;
		} else {
			i += 1;
		}
		length++;
	}
	return length;
}

size_t Table_output::max_strlen(const std::vector<size_t> &v)
{
	const auto result = std::max_element(v.cbegin(), v.cend());

	return *result;
}

auto Table_output::get_column_cells_widths(const size_t& col_pos) -> std::vector<size_t>
{
	std::vector<size_t> column;
	for (const auto& row : v_table_data_) {
		column.push_back({row.at(col_pos).length});
	}
	return column;
}

//===========================форматирование ячейки=====================================

auto Table_output::cell_format(const std::string &str, const size_t &column_width) -> std::stringstream
{
}

auto Table_output::cell_width() -> std::stringstream
{
	std::stringstream ss;
	ss <<
}

auto Table_output::horizont_table_frame() -> std::stringstream
{
}

//===========================функции конструктора=====================================


bool Table_output::is_rows_length_same() const
{
	for (const auto& row : v_table_data_) {
		if (row.size() != table_width) {
			return false;
		}
	}
	return true;
}

void Table_output::data_processing()
{

}

//*****************************************************************
//	PUBLIC
//*****************************************************************

Table_output::Table_output(const std::vector<std::vector<std::string>> &v_table_data)
{
	table_width = v_table_data.at(0).size();
	table_height = v_table_data.size();

	for (int y = 0; y < table_height; y++) {
		for (const auto& str : v_table_data.at(y)) {
			v_table_data_.at(y).push_back({str, strlen(str)});
		}
	}

	if (!is_rows_length_same()) {
		throw std::invalid_argument(
			"Все строки таблицы должны быть одинакавого размера");
	}

	v_column_standard_widths_.resize(table_width);

	for (int x = 0; x < table_width; x++) {
		v_column_standard_widths_.at(x) = get_column_cells_widths(x);
	}

}

void Table_output::add_titles(const std::vector<std::string> &v_titles)
{

}

//===========================геттеры=====================================

auto Table_output::get_data() const -> std::vector<std::vector<std::string>>
{

}

std::vector<std::string> Table_output::get_row(size_t pos) const
{

}

std::string Table_output::get_cell(size_t row_pos, size_t col_pos) const
{

}

//===========================операторы=====================================

std::ostream & operator<<(std::ostream &os, const Table_output &obj)
{

}






