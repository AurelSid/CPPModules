#include "PmergeMe.hpp"

Pmerge_me::Pmerge_me(int argc, char **argv)
{
    nums_count = 0;
    for (int i = 1; i < argc; i++)
    {
        this->start_list.push_back(atoi(argv[i]));
        std::cout << argv[i] << " pushed to list" << std::endl;
        nums_count++;
    }
    std::cout << "Nums count: " << nums_count << std::endl;
    sort();
}
Pmerge_me::~Pmerge_me()
{
}
Pmerge_me::Pmerge_me(Pmerge_me &other)
{
    (void)other;
}
void Pmerge_me::sort()
{
    std::cout << "Before pairwise swap:\n";
    for (std::list<int>::iterator it = start_list.begin(); it != start_list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::list<int>::iterator it = start_list.begin();
    std::cout << std::endl;
    while (it != start_list.end())
    {
        std::list<int>::iterator next = it;
        std::advance(next, 1);

        if (next == start_list.end())
            break;

        if (*it < *next)
        {
            std::iter_swap(it, next);
        }

        std::advance(it, 2);
    }

    std::cout << "After pairwise swap:\n";
    for (std::list<int>::iterator it = start_list.begin(); it != start_list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
