/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_converter.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:38:22 by roko              #+#    #+#             */
/*   Updated: 2025/03/19 09:20:03 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdlib>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter &other);
    ~ScalarConverter();
    ScalarConverter &operator=(ScalarConverter const &rSym);

public:
    static void convert(std::string cpp_lit);
};

#endif