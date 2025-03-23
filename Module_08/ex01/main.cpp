/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:29:42 by roko              #+#    #+#             */
/*   Updated: 2025/03/23 20:59:28 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <vector>

void printVector(const std::vector<int> &vec)
{
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    srand(time(NULL));

    Span array(50);
    try
    {
        array.addMultNumbers(10);
        std::cout << array.longestSpan() << std::endl;
        std::cout << array.shortestSpan() << std::endl;
    }
    catch (const Span::maxArrayException &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    catch (const Span::emptyArrayException &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
