/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:11:26 by roko              #+#    #+#             */
/*   Updated: 2025/03/19 09:11:39 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar_converter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert [string]" << std::endl;
        return (0);
    }

    ScalarConverter::convert(av[1]);

    return 0;
}