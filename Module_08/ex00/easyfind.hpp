/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:04:05 by roko              #+#    #+#             */
/*   Updated: 2025/03/21 14:39:01 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <stdexcept>

class no_num : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Not in the container.";
    }
};
template <typename Type>
int easyfind(Type container, int num)
{
    typename Type::iterator start;
    for (start = container.begin(); start != container.end(); ++start)
    {
        if (*start == num)
            return *start;
    }
    throw no_num();
}

#endif