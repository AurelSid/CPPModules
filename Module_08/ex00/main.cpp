/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:27:17 by roko              #+#    #+#             */
/*   Updated: 2025/03/21 14:40:45 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{

    std::list<int> my_array;
    my_array.push_back(1);
    my_array.push_back(2);
    my_array.push_back(3);
    my_array.push_back(4);
    my_array.push_back(5);

    try
    {
        std::cout << easyfind(my_array, 4) << std::endl;
        std::cout << easyfind(my_array, 10) << std::endl;
    }
    catch (const no_num &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
