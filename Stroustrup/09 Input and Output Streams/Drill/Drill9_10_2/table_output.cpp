//
// Created by consent_ on 07-Apr-25.
//

#include "table_output.h"

#include <iomanip>
#include <stdexcept>

Table_output::cell::cell(const std::string& cell_content)
	: content(cell_content)
{
	length = strlen(content);
}

//*****************************************************************
//	ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
//*****************************************************************

std::array<std::string, 3> Table_output::frame::get_borders(const pos p)
{
	switch (p) {
		case title:
			return title_borders;
		case mid:
			return mid_borders;
		case end:
			return end_borders;
		default:
			throw std::invalid_argument("Table_output::frame::get_borders: Invalid position");
	}
}

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

void Table_output::print_raw_data()
{
	for (const auto& row : v_table_data_) {
		for (const auto& cell : row	) {
			std::cout << cell.content << ' ' << cell.length << '\t';
		}
		std::cout << '\n';
	}
	std::cout << "v_table_data_.size() = " << v_table_data_.size() << '\n';
}

//===========================форматирование ячейки=====================================

auto Table_output::cell_format(const size_t& y_pos,  const size_t& x_pos) const -> std::stringstream
{
	std::stringstream ss;

	ss << frame::col << ' ' << v_table_data_.at(y_pos).at(x_pos).content
	   << std::string(v_column_standard_widths_.at(x_pos)- v_table_data_.at(y_pos).at(x_pos).length, ' ') << ' ';

	if (x_pos == v_table_data_.at(y_pos).size() - 1) {
		ss << frame::col;
	}
	return ss;
}

auto Table_output::horizontal_table_frame(const frame::pos p) const -> std::stringstream
{
	std::stringstream ss;

	const std::array borders = frame::get_borders(p);

	for (int x = 0; x < table_width; x++) {
		if (x == 0 ) {
			ss << borders.at(frame::title);
		}
		else {
			ss << borders.at(frame::mid);
		}
		ss << fill_frame(v_column_standard_widths_.at(x));
	}
	ss << borders.at(frame::end);
	return ss;
}

std::string Table_output::fill_frame(const size_t &width)
{
	std::string row;
	for (int x = 0; x < width + 2; x++) {
		row += frame::row;
	}
	return row;
}

//===========================функции конструктора=====================================


bool Table_output::is_rows_length_same() const
{
	for (const auto& row : v_table_data_) {
		if (row.size() != table_width) {
			std::cerr << "table_width: " << table_width << "\trow size:" << row.size() << '\n';
			return false;
		}
	}
	return true;
}

//*****************************************************************
//	PUBLIC
//*****************************************************************

Table_output::Table_output(const std::vector<std::vector<std::string>> &v_table_data)
{
	table_width = v_table_data.at(0).size();
	table_height = v_table_data.size();

	try {
		for (const auto& row : v_table_data) {

			std::vector <cell> v_temp;

			for (const std::string& str_data : row) {
			v_temp.push_back({str_data});
			}
			v_table_data_.push_back(v_temp);

		}
		print_raw_data();
	}
	catch (const std::out_of_range &e) {
		print_raw_data();
		throw std::out_of_range("Table_output constructor: ");
	}
	if (!is_rows_length_same()) {
		print_raw_data();
		throw std::invalid_argument(
			"Table_output constructor: rows length mismatch");
	}

	v_column_standard_widths_.resize(table_width);

	for (int x = 0; x < table_width; x++) {
		v_column_standard_widths_.at(x) = max_strlen(get_column_cells_widths(x));
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

std::ostream & operator<<(std::ostream &os, const Table_output& obj)
{
	for (int y = 0; y < obj.table_height; y++) {
		if (y == 0)
			os << obj.horizontal_table_frame(Table_output::frame::title).str() << '\n';
		for (int x = 0; x < obj.table_width; x++) {
			os << obj.cell_format(y, x).str();
		}
		os << '\n';
		if (y == 0)
			os << obj.horizontal_table_frame(Table_output::frame::mid).str() << '\n';
		if (y == obj.table_height-1) {
			os << obj.horizontal_table_frame(Table_output::frame::end).str() << '\n';
		}

	}

	return os;
}

int main()
{
	try {
		Table_output obj{
			{
				{"Имя", "Фамилия", "Номер", "Электронная Почта"},
				{"Иван", "Иванов", "+79161234567", "ivanov.ivan@mail.ru"},
				{"Мария", "Петрова", "+79259876543", "petrova.maria@gmail.com"},
				{"Алексей", "Сидоров", "+79035432109", "sidorov.alex@yandex.ru"}
			}
		};
		std::cout << obj << '\n';
	}
	catch (const std::out_of_range &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	catch (const std::invalid_argument &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 2;
	}
	/*catch (...) {
		std::cerr << "Unknown error."  << std::endl;
		return 228;
	}*/


	return 0;
}





