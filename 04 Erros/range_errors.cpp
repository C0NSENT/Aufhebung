//
// Created by consent_ on 08-Mar-25.
//

#include <vector>
#include <stdexcept>
#include <iostream>

int main(void)
{
    std::vector<int> v;
    for (int x; std::cin >> x;)
        v.push_back(x);

    try
    {
        for (int i = 0; i <= v.size(); i++)
            std::cout << "v[" << i << "] == " << v.at(i) << '\n';
    }
    catch(const std::range_error& re)
    {

    }
    catch (const std::out_of_range& oor)
    {
        std::cerr << "\nНового года не будет " << oor.what() << " принял ислам\n";
        return 228;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << "Нового года не будет " << e.what() << " принял ислам\n";
        return 228;
    }

    catch (...)
    {
        std::cerr << "Exception: something went wrong\n";
        return 2;
    }
}
