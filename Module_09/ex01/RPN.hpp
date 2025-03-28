#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <stack>

class RPN
{
private:
    RPN(); // Private constructor
    ~RPN();

    bool _check_input(std::string input);
    int _operation(std::string token);
    float _calculate(char o, float num1, float num2);

    std::stack<double> _array;

public:
    static int result(std::string input);
};

#endif
