//
// Created by consent_ on 05-Apr-25.
//

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <numeric>

/**
 * Выдает таблицу символов, их размер в байтах и длину.
 * В принципе все работате только правда с центрированием utf8 символов
 * т.к. они разной длина из-за этого таблица съезжает
 */

//TODO
// Починить центрирование текста, т.к. мой костыль не работает(

class Table
{
	static size_t utf8_strlen(const std::string &s)
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

	//юзлесс ебанный(
	static size_t max_str_len( const std::vector<std::string>& v, const std::string & title)
	{
		// оставляю чисто потому что это лямбда фунцкция мне нравится, красивое
		const auto max_element_ptr = std::max_element(v.begin(), v.end(), [ ]
			(const std::string& first, const std::string &second)
			{ return utf8_strlen(first) < utf8_strlen(second); }
			);

		const auto max_element_length = utf8_strlen(*max_element_ptr);
		const auto title_length = utf8_strlen(title);

		return (max_element_length > title_length) ? max_element_length : title_length;
	}

	static std::string cell_format(const std::string& str, const size_t& cell_size)
	{
		std::stringstream ss;
		ss << " " << std::left << std::setw(cell_size) << std::setfill(' ') << str;
		return ss.str();
	}

	static size_t text_centering(const std::string& str)
	{
		if (str.size() == 4  )
			return 3;
		return str.size();

	}

	static void table_print_vector(
		const std::vector<std::string>& v_characters,
		const std::vector<size_t>& v_cell_len)
	{
		for (const auto & str : v_characters) {

			std::cout << cell_format(str, v_cell_len.at(0) + text_centering(str))
					  << cell_format(std::to_string(str.size()), v_cell_len.at(1))
					  << cell_format(std::to_string(utf8_strlen( str)), v_cell_len.at(2)) << '\n';
		}
	}


	static auto utf8_vector_len(const std::vector<std::string>& v) -> std::vector<size_t>
	{
		std::vector<size_t> result;
		result.reserve(v.size());

		for (const auto& s : v) {
			result.push_back(utf8_strlen(s));
		}
		return result;
	}

public:

	static void print(const std::vector<std::string>& v)
	{
		const std::string title1{"character"};
		const std::string title2{"size(in bytes)"};
		const std::string title3{"length"};

		const std::vector<size_t> v_cell_len = {
		utf8_strlen(title1) +4,
		utf8_strlen(title2) +4,
		utf8_strlen(title3) +4
		};

		std::cout << cell_format(title1,v_cell_len.at(0))
				  << cell_format(title2, v_cell_len.at(1))
				  << cell_format(title3, v_cell_len.at(2)) << std::endl;

		std::cout << std::setw( std::reduce(v_cell_len.begin(), v_cell_len.end()))
				  << std::setfill('-') << "--" << std::endl;

		table_print_vector(v, v_cell_len);
	}

};

int main()
{
	const std::vector<std::string> utf8_chars{
		// 1-байтовые символы (ASCII)
		"A",                 // Латинская 'A'
		"z",                 // Латинская 'z'
		"7",                 // Цифра

		// 2-байтовые символы (кириллица, акценты)
		"\u0430",            // Кириллическая 'а' (U+0430)
		"\xC3\xB1",          // Испанская 'ñ' (U+00F1)

		// 3-байтовые символы
		"\u20AC",            // Символ евро '€' (U+20AC)
		"\xE2\x98\x85",      // Звезда '★' (U+2605)

		// 4-байтовые символы (эмодзи, иероглифы)
		"\xF0\x9F\x9A\x80",  // Ракета '🚀' (U+1F680)
		"\xF0\x9F\x98\x8A",  // Улыбка '😊' (U+1F60A)
		"\xF0\x9F\x8D\x95",  // Пицца '🍕' (U+1F355)
		"\xF0\x9F\xA6\x96"   // Попугай '🦖' (U+1F996)
	};
try {
	Table::print(utf8_chars);
}
	catch (const std::out_of_range& e) {
		std::cerr << "Error:" << e.what() << std::endl;
		return 1;
	}

}