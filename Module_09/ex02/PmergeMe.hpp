#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <deque>
#include <cstring>
class Pmerge_me
{
public:
    std::deque<int> start_list;
    std::deque<int> end_list;

private:
    int nums_count;
};

#endif