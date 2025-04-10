#include "PmergeMe.hpp"

Pmerge_me::Pmerge_me(int argc, char **argv)
{
    std::vector<int> _list;
    for (int i = 1; i < argc; i++)
    {
        _list.push_back(atoi(argv[i]));
        // std::cout << argv[i] << " pushed to list" << std::endl;
    }
    sort(_list);
}
Pmerge_me::~Pmerge_me()
{
}
Pmerge_me::Pmerge_me(Pmerge_me &other)
{
    (void)other;
}

static void print_vector(const std::vector<int> &vec)
{
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

static int groups_num_is_even(int gr_count)
{
    if (gr_count % 2 == 1)
        std::cout << (gr_count % 2 == 1) << ": Uneven gr_cont" << std::endl;

    return (gr_count % 2 == 1);
}
int Jacobsthal(int k)
{
    return round((pow(2, k + 1) + pow(-1, k)) / 3);
}
void Pmerge_me::sort(std::vector<int> &vec)
{
    std::cout << "====================" << std::endl;
    std::cout << "L size: " << vec.size() << std::endl;

    static int gr_size = 1;
    int gr_count = vec.size() / gr_size;
    std::cout << "Current gr size: " << gr_size << std::endl;
    std::cout << "Current gr count: " << gr_count << std::endl;

    if (gr_count < 2)
        return;

    bool list_uneven = groups_num_is_even(gr_count);
    std::vector<int>::iterator start = vec.begin();
    std::vector<int>::iterator end = vec.begin();
    if (list_uneven)
        end = vec.begin() + gr_size * gr_count;
    else
        end = vec.begin() + (gr_size * gr_count) - gr_size;
    if (end == vec.end())
        --end;

    std::cout << *start << std::endl;
    std::cout << *end << std::endl;

    for (std::vector<int>::iterator it = start; it + gr_size * 2 <= vec.end(); it += gr_size * 2)

    {

        std::cout << "Comparing: " << *(it + gr_size - 1) << " with " << *(it + (gr_size * 2) - 1) << std::endl;
        if (*(it + gr_size - 1) > *(it + (gr_size * 2) - 1))
            std::swap_ranges(it, it + gr_size, it + gr_size);

        std::cout << *(it + gr_size - 1) << " > " << *(it + (gr_size * 2) - 1) << std::endl;
    }

    gr_size *= 2;
    print_vector(vec);
    sort(vec);
    gr_size /= 2;
    std::vector<int> main;
    std::vector<int> pend;
    std::vector<int> non_sorted;

    for (std::vector<int>::iterator it = start; it < (start + gr_size); it++)
    {
        main.push_back(*it);
    }
    for (std::vector<int>::iterator it = start + gr_size; it + gr_size * 2 <= vec.end(); it += gr_size * 2)
    {
        for (std::vector<int>::iterator it_2 = it; it_2 < (it + gr_size); it_2++)
        {
            main.push_back(*it_2);
        }
    }
    for (std::vector<int>::iterator it = start + gr_size * 2; it + gr_size <= vec.end(); it += gr_size * 2)
    {
        for (std::vector<int>::iterator it_2 = it; it_2 < (it + gr_size); it_2++)
        {
            pend.push_back(*it_2);
        }
    }
    if (list_uneven)
        for (std::vector<int>::iterator it = end; it < vec.end(); it++)
            non_sorted.push_back(*it);
    std::cout << "Main: ";
    std::cout << "gr_size : " << gr_size << std::endl;
    print_vector(main);
    std::cout << "non_sorted: ";
    print_vector(non_sorted);
    std::cout << "Pend: ";
    print_vector(pend);
    std::cout << "========" << std::endl;
}
