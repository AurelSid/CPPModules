/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:11:59 by roko              #+#    #+#             */
/*   Updated: 2025/04/09 12:09:58 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Err: use : ./exe [min 2 ints to sort]" << std::endl;
    }
    for (size_t i = 1; i < (size_t)argc; i++)
    {
        for (size_t j = 0; j < std::strlen(argv[i]); j++)
        {
            if (!isdigit(argv[i][j]))
                std::cerr << "Err: Invalid input detected" << std::endl;
        }
    }

    Pmerge_me list(argc, argv);
}
