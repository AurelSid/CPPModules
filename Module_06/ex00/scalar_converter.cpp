/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_converter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:39:51 by babreton          #+#    #+#             */
/*   Updated: 2025/03/19 09:21:46 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar_converter.hpp"

static void conv_char(std::string param)
{
    std::cout << "char_converted: " << param[0] << std::endl;
    std::cout << "int_converted: " << static_cast<int>(param[0]) << std::endl;
    std::cout << "float_converted: " << std::fixed << std::setprecision(1) << static_cast<float>(param[0]) << "f" << std::endl;
    std::cout << "double_converted: " << std::fixed << std::setprecision(1) << static_cast<double>(param[0]) << std::endl;
}

static void conv_int(std::string param)
{
    if (atoi(param.c_str()) < 0 || atoi(param.c_str()) > 127)
        std::cout << "char_converted: impossible" << std::endl;
    else if (atoi(param.c_str()) < 32 || atoi(param.c_str()) == 127)
        std::cout << "char_converted: non-displayable" << std::endl;
    else
        std::cout << "char_converted: " << static_cast<char>(atoi(param.c_str())) << std::endl;
    std::cout << "int_converted: " << atoi(param.c_str()) << std::endl;
    std::cout << "float_converted: " << std::fixed << std::setprecision(1) << static_cast<float>(atoi(param.c_str())) << "f" << std::endl;
    std::cout << "double_converted: " << std::fixed << std::setprecision(1) << static_cast<double>(atoi(param.c_str())) << std::endl;
}

static void conv_float(std::string param)
{
    if (atof(param.c_str()) < 0 || atof(param.c_str()) > 127)
        std::cout << "char_converted: impossible" << std::endl;
    else if (atof(param.c_str()) < 32 || atof(param.c_str()) == 127)
        std::cout << "char_converted: non-displayable" << std::endl;
    else
        std::cout << "char_converted: " << static_cast<char>(atof(param.c_str())) << std::endl;
    std::cout << "int_converted: " << static_cast<int>(atof(param.c_str())) << std::endl;
    std::cout << "float_converted: " << std::fixed << std::setprecision(2) << atof(param.c_str()) << "f" << std::endl;
    std::cout << "double_converted: " << std::fixed << std::setprecision(2) << static_cast<double>(atof(param.c_str())) << std::endl;
}

static void conv_dbl(std::string param)
{
    if (atof(param.c_str()) < 0 || atof(param.c_str()) > 127)
        std::cout << "char_converted: impossible" << std::endl;
    else if (atof(param.c_str()) < 32 || atof(param.c_str()) == 127)
        std::cout << "char_converted: non-displayable" << std::endl;
    else
        std::cout << "char_converted: " << static_cast<char>(atof(param.c_str())) << std::endl;
    std::cout << "int_converted: " << static_cast<int>(atof(param.c_str())) << std::endl;
    std::cout << "float_converted: " << std::fixed << std::setprecision(2) << static_cast<float>(atof(param.c_str())) << "f" << std::endl;
    std::cout << "double_converted: " << std::fixed << std::setprecision(2) << atof(param.c_str()) << std::endl;
}

static void min_inf_conv()
{
    std::cout << "char_converted: impossible" << std::endl;
    std::cout << "int_converted: " << INT_MIN << std::endl;
    std::cout << "float_converted: " << __FLT_MIN__ << std::endl;
    std::cout << "double_converted: " << __DBL_MIN__ << std::endl;
}

static void max_inf_conv()
{
    std::cout << "char_converted: impossible" << std::endl;
    std::cout << "int_converted: " << INT_MAX << std::endl;
    std::cout << "float_converted: " << __FLT_MAX__ << std::endl;
    std::cout << "double_converted: " << __DBL_MAX__ << std::endl;
}

static void nan()
{
    std::cout << "char_converted: impossible" << std::endl;
    std::cout << "int_converted: " << 0 << std::endl;
    std::cout << "float_converted: " << 0 << std::endl;
    std::cout << "double_converted: " << 0 << std::endl;
}

static void error()
{
    std::cout << "char_converted: impossible" << std::endl;
    std::cout << "int_converted: " << 0 << std::endl;
    std::cout << "float_converted: " << 0 << std::endl;
    std::cout << "double_converted: " << 0 << std::endl;
}

static void checkInput(std::string param)
{
    if (std::isprint(param[0]) && !std::isdigit(param[0]))
    {
        if (param.length() == 1)
            conv_char(param);
        else if (param == "-inf" || param == "-inff")
            min_inf_conv();
        else if (param == "+inf" || param == "+inff")
            max_inf_conv();
        else if (param == "nan" || param == "nanf")
            nan();
        else
            error();
    }
    else if (param[param.length() - 1] == 'f')
    {
        long unsigned int i = 0;
        while (i < param.length() - 1 && (std::isdigit(param[i]) || param[i] == '.'))
            i++;
        if (i == param.length() - 1)
            conv_float(param);
        else
            error();
    }
    else if (param.find('.') != std::string::npos)
    {
        long unsigned int i = 0;
        while (std::isdigit(param[i]) || param[i] == '.')
            i++;
        if (i == param.length())
            conv_dbl(param);
        else
            error();
    }
    else if (std::isdigit(param[0]))
    {
        long unsigned int i = 0;
        while (std::isdigit(param[i]))
            i++;
        if (i == param.length())
            conv_int(param);
        else
            error();
    }
    else
        error();
}

void ScalarConverter::convert(std::string param)
{
    checkInput(param);
}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter &other)
{
    static_cast<void>(other);
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    static_cast<void>(other);
    return *this;
}
