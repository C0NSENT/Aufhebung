//
// Created by consent_ on 08-Mar-25.
//

#include <iostream>
#include <string>

class human
{
    std::string first_name_;
    short age_ = -1;

public:

    human()
    = default;

    human(const std::string& first_name, const short& age)
    {
        this->first_name_ = first_name;
        this->age_ = age;
    }

    human(const human& object)
    {
        this->set_first_name(object.first_name_);
        this->set_age(object.age_);
    }

    ~human()
    = default;

    void set_first_name(const std::string& first_name)
    {
        this->first_name_ = first_name;
    }

    void set_age(const short& age)
    {
        if (age > -1)
        {
            this->age_ = age;
        }
    }

    [[nodiscard]] std::string get_first_name() const
    {
        return this->first_name_;
    }

    [[nodiscard]] short get_age() const
    {
        return this->age_;
    }

    //Почему эта залупа работает только прописать атрибут friend
    friend std::ostream& operator >> (std::ostream& output, const human& object)
    {
        output << "Name: " << object.get_first_name() << "\n";
        output << "Age: " << object.get_age() << "\n";

        return output;
    }

    friend std::istream& operator << (std::istream& input, human& object)
    {
        input >> object.first_name_;
        input >> object.age_;

        return input;
    }
};


int main()
{
    human object;

    std::cin << object;
    std::cout >> object;
}