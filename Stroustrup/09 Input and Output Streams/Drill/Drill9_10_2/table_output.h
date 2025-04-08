//
// Created by consent_ on 07-Apr-25.
//

#ifndef TABLE_OUTPUT_H
#define TABLE_OUTPUT_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

// Можно забить болт setw() и выводить напрямую длину
// std::string((column_width- strlen(s)), '');

class Table_output
{

	struct /*splinter*/ cell
	{
		std::string content;
		size_t length;

		cell(const std::string& cell_content);
	};

	struct frame
	{
		enum pos : unsigned short
		{
			title,
			mid,
			end
		};
		constexpr static std::string col{"│"}, row{ "─"},
								 cornerLU{"┌"}, cornerRU{"┐"},
								 cornerLD{"└"}, cornerRD{"┘"},
								 //InterSection Column Right
								 isColR{"├"}, isColL{"┤"},
								 isRowD{"┬"}, isRowU{"┴"}, isMid{"┼"};

		constexpr static std::array title_borders{cornerLU, isRowD, cornerRU};
		constexpr static std::array mid_borders{isColR, isMid, isColL};
		constexpr static std::array end_borders{cornerLD, isRowU, cornerRD};

		static std::array<std::string, 3> get_borders(const pos p);
	};

	//*****************************************************************
	//	СВОЙСТВА
	//*****************************************************************

	std::vector<std::vector<cell>> v_table_data_;
	std::vector<size_t> v_column_standard_widths_;

	int table_width, table_height;

	//*****************************************************************
	//	ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
	//*****************************************************************

	[[nodiscard]] static size_t strlen(const std::string &s);
	[[nodiscard]] static size_t max_strlen (const std::vector<size_t>& v);

	auto get_column_cells_widths(const size_t& col_pos) -> std::vector<size_t>;

	void print_raw_data();

	//===========================форматирование ячейки=====================================

	auto cell_format(const size_t& y_pos,  const size_t& x_pos) const -> std::stringstream;
	auto cell_width() -> std::stringstream;
	auto horizontal_table_frame(const frame::pos p) const -> std::stringstream;

	static std::string fill_frame(const size_t& width);

	//===========================функции конструктора=====================================

	bool is_rows_length_same() const;

public:
	//*****************************************************************
	//	PUBLIC
	//*****************************************************************

	explicit Table_output(const std::vector<std::vector<std::string>>& v_table_data);

	//по приколу
	void add_titles(const std::vector<std::string>& v_titles);

	//===========================геттеры=====================================

	auto get_data() const  -> std::vector<std::vector<std::string>>;
	std::vector<std::string> get_row(size_t pos) const;
	std::string get_cell(size_t row_pos, size_t col_pos) const;

	//===========================операторы=====================================

	friend std::ostream& operator<<(std::ostream& os, const Table_output& obj);
};

#endif //TABLE_OUTPUT_H