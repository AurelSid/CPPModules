#include "RPN.hpp"

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
bool RPN::_check_input(std::string input)
{
    int operandCount = 0;
    int operatorCount = 0;
    std::string token;
    std::string::size_type pos = 0;

    while (pos < input.length())
    {

        while (pos < input.length() && input[pos] == ' ')
            pos++;
        if (pos >= input.length())
            break;

        if (isdigit(input[pos]))
        {
            token.clear();
            while (pos < input.length() && isdigit(input[pos]))
            {
                token += input[pos];
                pos++;
            }
            operandCount++;
        }
        else if (isOperator(input[pos]))
        {
            token = input[pos];
            operatorCount++;
            pos++;

            if (operandCount < operatorCount + 1)
            {
                std::cerr << "Error: Invalid RPN syntax. Not enough operands for '"
                          << token << "'" << std::endl;
                return false;
            }
        }
        else
        {
            std::cerr << "Error: Invalid token '" << input[pos] << "'" << std::endl;
            return false;
        }
    }
    if (operandCount - operatorCount != 1)
    {
        std::cerr << "Error: Invalid RPN expression. Mismatch between operands and operators."
                  << std::endl;
        return false;
    }

    return true;
}
float RPN::_calculate(char o, float num1, float num2)
{
    if (o == '+')
    {
        return (num1 + num2);
    }
    else if (o == '-')
    {
        return (num1 - num2);
    }
    else if (o == '*')
    {
        return (num1 * num2);
    }
    else if (o == '/')
    {
        if (num2 == 0)
        {
            std::cerr << "Error: Division by zero!" << std::endl;
            exit(1);
        }
        return (num1 / num2);
    }
    std::cerr << "Error: Unknown operator '" << o << "'" << std::endl;
    exit(1);
}

int RPN::_operation(std::string input)
{

    std::string token;
    std::string::size_type pos = 0;
    float temp;
    float temp2;
    while (pos < input.length())
    {

        while (pos < input.length() && input[pos] == ' ')
            pos++;
        if (pos >= input.length())
            break;
        if (isdigit(input[pos]))
        {
            while (pos < input.length() && isdigit(input[pos]))
            {
                token += input[pos];
                // std::cout << token << " ==> pushed to stack" << std::endl;
                pos++;
            }
            _array.push(atoi(token.c_str()));
            token.clear();
        }

        else if (isOperator(input[pos]))
        {
            temp2 = _array.top();
            _array.pop();
            temp = _array.top();
            _array.pop();
            _array.push(_calculate(input[pos], temp, temp2));
            // std::cout << _calculate(input[pos], temp, temp2) << " ==> pushed to stack" << std::endl;

            pos++;
        }
    }

    return true;
}

int RPN::result(std::string input)
{
    RPN rpnInstance;
    if (rpnInstance._check_input(input) == false)
        return 0;
    ;
    rpnInstance._operation(input);
    std::cout << rpnInstance._array.top() << std::endl;

    return 1;
}

RPN::RPN() {}
RPN::~RPN() {}
