//
// Created by consent_ on 05-Apr-25.
//

/*
 * На вход принимается четыре строковых вектора
 * При определении объекта вектора заносятся в двухмерный массив
 * Также в конструкторе идет проверка на совпадение размеров векторов,
 * а также добавляется в начало будущий заголовок столбца
 *
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>


class Data_table
{
	std::array <std::vector<std::string>, 4> data;

	constexpr static std::array <std::string, 4> title{
		"First Name", "Last Name", "Phone Number", "Email"
	};

	static size_t strlen(const std::string &s)
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

	static size_t max_str_len (const std::vector<std::string>& v)
	{
		const auto result = std::max_element(v.begin(), v.end(), [ ]
			(const std::string& first, const std::string &second)
			{ return strlen(first)< strlen(second); }
		);
		return strlen(*result);
	}

	auto column_widths() -> std::vector<size_t>
	{
		std::vector<size_t> v_column_width;
		for (const auto& str_vec : data) {
			v_column_width.push_back(max_str_len(str_vec) + 2);
		}
		return v_column_width;
	}

	static std::string cell_format(const std::string& str, const size_t& column_width)
	{
		//костыль(
		int width_correction{-1};
		if ( unsigned char c = str.at(0); (c & 0xE0) == 0xC0 )
				width_correction += strlen(str);

		std::stringstream ss;
		ss << "│ " << std::setfill(' ') << std::setw(column_width + width_correction) << std::left << str;
		return ss.str();
	}

	std::string output_row(const std::vector<std::string>& v_str_row, const std::vector<size_t>& v_column_widths)
	{
		std::stringstream ss;

		for (auto i = 0; i < v_str_row.size(); i++) {
			ss << cell_format(v_str_row.at(i), v_column_widths.at(i));
		}

		ss << "│";

		return ss.str();
	}

	static std::string set_row(const size_t& column_width)
	{
		constexpr std::string row{"─"};
		std::string result;
		for (auto i = 0; i < column_width; i++) {
			result += row;
		}
		return result;
	}

	std::string output_frame(const std::vector<std::string>& v_frame, const std::vector<size_t>& v_column_widths )
	{
		std::stringstream ss;
		ss << v_frame.at(0);

		int type{1};

		for (auto i = 0; i < v_column_widths.size(); i++) {
			if (i == v_column_widths.size() - 1)
				type++;

			ss << set_row(v_column_widths.at(i)) << v_frame.at(type);
		}


		return ss.str();
	}

	//====================Вспомогательные функции конструктора==========================
	bool is_vectors_size_same() const
	{
		const auto size = data.at(0).size();
		for (auto i = 1; i < 4; i++) {
			if (data.at(i).size() != size) return false;
		}
		return true;
	}

	void data_processing()
	{
		for (auto i = 0; i < 4; i++) {
			data.at(i)
			.insert(data.at(i).begin(), title.at(i))
			->reserve(data.at(i).size());
		}
	}

	public:

	explicit Data_table(const std::vector<std::string> &v_first_names,
		const std::vector<std::string> &v_last_names,
		const std::vector<std::string> &v_phone_numbers,
		const std::vector<std::string> &v_emails
	)
	: data{v_first_names, v_last_names, v_phone_numbers, v_emails}
	{
		if (!is_vectors_size_same()) {
			throw std::invalid_argument("Размеры векторов не совпадают");
		}
		data_processing();
	}

	//====================ГНИДА=================================
	void print_table()
	{
		constexpr std::string col{"│"};
		constexpr std::string cornerLU{"┌"}, cornerRU{"┐"},
							  cornerLD{"└"}, cornerRD{"┘"};
		//InterSection Column Right
		constexpr std::string isColR{"├"}, isColL{"┤"},
							  isRowD{"┬"}, isRowU{"┴"}, isMid{"┼"};

		const std::vector title_upper_frame{cornerLU,   isRowD, cornerRU};
		const std::vector title_down_frame{isColR,  isMid, isColL};
		const std::vector table_end{cornerLD, isRowU,  cornerRD};

		const std::vector v_column_width{std::move(column_widths())};


		for (auto i = 0 ; i < data.at(0).size() ; i++) {

			std::vector<std::string> v_row;

			for (auto j = 0 ; j < data.size() ; j ++) {
				v_row.push_back(data.at(j).at(i));
			}

			if (i == 0) {
				std::cout << output_frame(title_upper_frame, v_column_width) << '\n'
						  << output_row(v_row, v_column_width) << '\n'
						  << output_frame(title_down_frame, v_column_width) << '\n';
			} else {
				std::cout << output_row(v_row, v_column_width) << '\n';
			}
		}
		std::cout << output_frame(table_end, v_column_width) << std::endl;
	}
};

int main()
{
	const std::vector<std::string> v_first_names{
		"Иван", "Мария", "Алексей", "Анна", "Дмитрий"
	};
	const std::vector<std::string> v_last_names {
		"Иванов", "Петрова", "Сидоров", "Смирнова", "Кузнецов"
	};
	const std::vector<std::string> v_numbers{
		"+79161234567",
		"+79259876543",
		"+79035432109",
		"+79521236789",
		"+79998765432"
	};
	const std::vector<std::string> v_emails {
		"ivanov.ivan@mail.ru",
		"petrova.maria@gmail.com",
		"sidorov.alex@yandex.ru",
		"smirnova.anna@inbox.com",
		"kuznetsov.dmitry@bk.ru"
	};

	Data_table dt{
		v_first_names, v_last_names, v_numbers, v_emails
	};

	dt.print_table();
}