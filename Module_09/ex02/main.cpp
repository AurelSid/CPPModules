#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Err: use : ./exe [min 2 ints to sort]" << std::endl;
    }
    for (size_t i = 1; i < (size_t)argc; i++)
    {
        for (size_t j = 0; j < std::strlen(argv[i]); j++)
        {
            if (!isdigit(argv[i][j]))
                std::cerr << "Err: Invalid input detected" << std::endl;
        }
    }
}