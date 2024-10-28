#include "../include/Utility/Utility.hpp"
#include <iostream>
#include <limits>

namespace N_Utility
{
    void Utility::ClearConsole()
    {
#ifdef _WIN32
        system("cls");
#else
        (void)system("clear");
#endif
    }

    void Utility::WaitForEnter()
    {
        std::cin.get();
    }

    void Utility::ClearInputBuffer()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}