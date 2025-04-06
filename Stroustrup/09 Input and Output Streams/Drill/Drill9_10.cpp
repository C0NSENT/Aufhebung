//
// Created by consent_ on 05-Apr-25.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
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
			unsigned char c = s.at(i);

			if (c < 0x80) {
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

	auto column_max_width() -> std::vector<size_t>
	{
		std::vector<size_t> v_max_str_len;
		v_max_str_len.reserve(data.size());

		std::vector<size_t> v_column_width;

		for (const auto& v : data) {
			v_max_str_len.push_back( max_str_len(v) );
		}

		for (size_t i = 0; i < 4; i++) {
			size_t collumn_width = (v_max_str_len.at(i) > strlen(title.at(i))) ? v_max_str_len.at(i) : strlen(title.at(i));
			v_column_width.push_back( collumn_width );
		}
		return v_column_width;
	}

	std::string cell_format(const std::string& str, const size_t& column_width)
	{
		std::stringstream ss;
		ss << std::setfill('0') << std::setw(column_width) << std::left << str;
		return ss.str();
	}

	std::string frame_format(const std::string& str, const size_t& column_width)
	{
		std::string result;
		for (auto i = 0; i < column_width; i++) {
			result += str;
		}
		return result;
	}

	public:

	explicit Data_table(const std::vector<std::string> &v_first_names,
		const std::vector<std::string> &v_last_names,
		const std::vector<std::string> &v_phone_numbers,
		const std::vector<std::string> &v_emails
	)
	: data{v_first_names, v_last_names, v_phone_numbers, v_emails}
	{
		data.at(0).reserve(v_first_names.size());
		data.at(1).reserve(v_last_names.size());
		data.at(2).reserve(v_phone_numbers.size());
		data.at(3).reserve(v_emails.size());
	}


	void print_table()
	{
		constexpr std::string col{"│"}, row{"─"};
		constexpr std::string cornerLU{"┌"}, cornerRU{"┐"},
							  cornerLD{"└"}, cornerRD{"┘"};
		//InterSection Column Right
		constexpr std::string isColR{"├"}, isColL{"┤"},
							  isRowD{"┬"}, isRowU{"┴"}, isMid{"┼"};

		std::vector<size_t> column_width{column_max_width()};
		std::cout << cornerLU <<frame_format( row, column_width.at(0)+2)
				  << isRowD << f

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