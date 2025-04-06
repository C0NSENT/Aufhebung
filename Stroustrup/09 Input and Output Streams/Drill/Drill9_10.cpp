//
// Created by consent_ on 05-Apr-25.
//

#include <iostream>
#include <string>
#include <vector>

class Data_table
{
	std::vector<std::string> v_first_names_;
	std::vector<std::string> v_last_names_;
	std::vector<std::string> v_phone_numbers_;
	std::vector<std::string> v_emails_;

	int get_cell_size (std::vector<std::string>& v)
	{

		//auto max_size = std::max_element(v.begin(), v.end(), [ ] (std::string* s )
		//	{return s->size();}
		//	);
		auto max_size = std::max_element(v.begin(), v.end());
		return max_size->size();
	}

	public:


	explicit Data_table(const std::vector<std::string> &v_first_names,
		const std::vector<std::string> &v_last_names,
		const std::vector<std::string> &v_phone_numbers,
		const std::vector<std::string> &v_emails
	)
	: v_first_names_(v_first_names)
	, v_last_names_(v_last_names)
	, v_phone_numbers_(v_phone_numbers)
	, v_emails_(v_emails) {}

	void print_table()
	{

	}
};

int main()
{
	const std::vector<std::string> v_first_names{
		//"John", "Emily", "Michael", "Sarah", "David"
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
		v_first_names,
		v_last_names,
		v_numbers,
		v_emails
	};

	 auto result = std::max_element(v_first_names.begin(), v_first_names.end(), [ ] (const std::string& first, const std::string &second) { return first.size() < second.size(); });

	std::cout <<  *result <<" "<<result->size() << "\n";
}