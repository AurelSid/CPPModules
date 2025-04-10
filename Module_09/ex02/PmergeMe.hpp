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
#include <cmath>

class Pmerge_me
{
private:
public:
    ~Pmerge_me();
    Pmerge_me(Pmerge_me &other);
    Pmerge_me(int argc, char **argv);
    void sort(std::vector<int> &vec);
};

#endif