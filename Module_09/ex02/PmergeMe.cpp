#include "PmergeMe.hpp"

// static void print_grouped_vector(constT &vec, int gr_size)
// {
//     if (vec.empty())
//     {
//         std::cout << "[empty]" << std::endl;
//         return;
//     }

//     for (size_t i = 0; i < vec.size(); i += gr_size)
//     {
//         std::cout << "[";
//         for (int j = 0; j < gr_size && (i + j) < vec.size(); j++)
//         {
//             std::cout << vec[i + j];
//             if (j != gr_size - 1 && (i + j + 1) < vec.size())
//                 std::cout << ",";
//         }
//         std::cout << "]";
//     }
//     std::cout << std::endl;
// }
template <typename T>
static void print_list(T &vec)
{
    for (typename T::iterator it = vec.begin(); it < vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

Pmerge_me::Pmerge_me(int argc, char **argv)
{
    clock_t before = clock();
    std::vector<int> _list;
    std::deque<int> _d;
    for (int i = 1; i < argc; i++)
    {
        int val = atoi(argv[i]);
        if (std::find(_list.begin(), _list.end(), val) == _list.end())
        {
            _list.push_back(val);
            _d.push_back(val);
        }
        else
        {
            std::cerr << "Duplicate value: " << val << " ignored." << std::endl;
        }
    }

    std::cerr << "Before sorting Vector: " << std::endl;
    print_list(_list);
    std::cerr << "Before sorting Deque: " << std::endl;
    print_list(_d);

    clock_t duration = clock() - before;
    sort(_list);
    std::cout << std::fixed << std::setprecision(8);
    std::cout << "Duration for Vector<int>: " << (float)duration / CLOCKS_PER_SEC << " seconds" << std::endl;
    duration = clock() - before;
    sort(_d);
    std::cout << "Duration for Deque: " << (float)duration / CLOCKS_PER_SEC << " seconds" << std::endl;

    std::cerr << "After sorting Vector: " << std::endl;
    print_list(_list);
    std::cerr << "After sorting Deque: " << std::endl;
    print_list(_d);
}
Pmerge_me::~Pmerge_me()
{
}
Pmerge_me::Pmerge_me(Pmerge_me &other)
{
    (void)other;
}

static int groups_num_is_even(int gr_count)
{
    return (gr_count % 2 == 1);
}
static int jacobsthal(int k)
{
    return round((pow(2, k + 1) + pow(-1, k)) / 3);
}
template <typename T>
typename T::iterator check_all_insert(int gr_size, T &main, int last_val)
{

    for (typename T::iterator it = main.begin() + gr_size - 1; it + gr_size <= main.end(); it += gr_size)
    {
        // std::cout << "Checking: " << *it << std::endl;

        if (last_val > *it)
        {
            if (it + gr_size >= main.end())
                return (main.end());
            if (last_val < *(it + gr_size))

                return it;
        }
        else
        {
            continue;
        }
    }

    return main.begin() - 1;
}
template <typename T>
static void insert_range(int gr_size,
                         T &main,
                         T &pend,
                         typename T::iterator insert_pos,
                         typename T::iterator range_start)
{
    if (range_start + gr_size > pend.end())
        return;
    if (insert_pos == main.end())
        main.insert(main.end(), range_start, range_start + gr_size);
    else
        main.insert(insert_pos + 1, range_start, range_start + gr_size);
    pend.erase(range_start, range_start + gr_size);
}
template <typename T>
void Pmerge_me::sort(T &vec)
{
    static int gr_size = 1;
    int gr_count = vec.size() / gr_size;

    // std::cout << "\n=== RECURSION START: gr_size = " << gr_size << ", vec size = " << vec.size() << " ===" << std::endl;

    if (gr_count < 2)
    {
        // std::cout << "Stopping recursion: not enough groups to proceed (gr_count = " << gr_count << ")" << std::endl;
        return;
    }

    bool list_uneven = groups_num_is_even(gr_count);
    typename T::iterator start = vec.begin();
    typename T::iterator end = vec.begin();

    if (list_uneven)
        end = vec.begin() + gr_size * gr_count;
    else
        end = vec.begin() + (gr_size * gr_count) - gr_size;

    // std::cout << "Swapping elements in adjacent groups if needed..." << std::endl;
    for (typename T::iterator it = vec.begin(); it + gr_size * 2 <= vec.end(); it += gr_size * 2)
    {

        if (*(it + gr_size - 1) > *(it + (gr_size * 2) - 1))
        {
            // std::cout << "Swapping ranges" << std::endl;
            std::swap_ranges(it, it + gr_size, it + gr_size);
        }
    }

    gr_size *= 2;
    sort(vec); // RECURSION HAPPENS HERE
    gr_size /= 2;

    // std::cout << "=== MERGING STAGE: gr_size = " << gr_size << " ===" << std::endl;

    T main;
    T pend;
    T non_sorted;

    // print_grouped_vector(vec, gr_size);
    for (typename T::iterator it = start; it < (start + gr_size); it++)
        main.push_back(*it);

    for (typename T::iterator it = start + gr_size; it + gr_size * 2 <= vec.end(); it += gr_size * 2)
    {
        for (typename T::iterator it_2 = it; it_2 < (it + gr_size); it_2++)
            main.push_back(*it_2);
    }

    for (typename T::iterator it = start + gr_size * 2; it + gr_size <= vec.end(); it += gr_size * 2)
    {
        for (typename T ::iterator it_2 = it;
             it_2 < (it + gr_size); it_2++)
            pend.push_back(*it_2);
    }

    // std::cout << "END: " << *end << std::endl;
    // std::cout << "S: " << *start << std::endl;
    for (typename T::iterator it = end; it < vec.end(); it++)
        non_sorted.push_back(*it);

    // std::cout << "Current main: ";
    // print_grouped_vector(main, gr_size);
    // std::cout << "Pending: ";
    // print_grouped_vector(pend, gr_size);
    // std::cout << "Non-sorted remainder: ";
    // print_grouped_vector(non_sorted, gr_size);

    int prev_jacobsthal = jacobsthal(1);

    for (int k = 2;; k++)
    {
        int curr_jacobsthal = jacobsthal(k);
        int reps = curr_jacobsthal - prev_jacobsthal;

        // std::cout << "--- Jacobsthal k=" << k << ", curr=" << curr_jacobsthal << ", prev=" << prev_jacobsthal << ", reps=" << reps << " ---" << std::endl;

        if ((size_t)(curr_jacobsthal * gr_size) > vec.size())
        {
            // std::cout << "Breaking Jacobsthal loop: index out of bounds" << std::endl;
            break;
        }

        while (reps)
        {

            typename T::iterator last_val = pend.begin() + (gr_size * reps - 1);
            typename T::iterator from_here = last_val - gr_size + 1;

            // std::cout << "Inserting group ending with value: " << *last_val << std::endl;

            typename T::iterator insert_here = check_all_insert(gr_size, main, *last_val);

            // if (insert_here == main.end())
            // std::cout << "Insert position is end of main" << std::endl;
            // else
            // std::cout << "Insert before: " << *insert_here << std::endl;

            insert_range(gr_size, main, pend, insert_here, from_here);

            // std::cout << "Pending after insert: ";
            // print_grouped_vector(pend, gr_size);
            // std::cout << "Main after insert: ";
            // print_grouped_vector(main, gr_size);

            reps--;
        }

        prev_jacobsthal = curr_jacobsthal;

        // std::cout << "Total treated numbers so far: " << treated_numbers << std::endl;
    }

    // std::cout << "Appending non-sorted elements to main..." << std::endl;
    main.insert(main.end(), non_sorted.begin(), non_sorted.end());
    non_sorted.clear();
    vec = main;

    // std::cout << "Main after final merge: ";
    // print_grouped_vector(main, gr_size);
    // std::cout << "======== RECURSION END (gr_size = " << gr_size << ") ========\n"
    //   << std::endl;
}
