/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:12:06 by roko              #+#    #+#             */
/*   Updated: 2025/03/26 13:20:56 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void check_file(char **argv)
{
    std::string file_name = argv[1];
    char *start_ptr = argv[1] + (std::strlen(argv[1]) - 4);
    if (std::strlen(argv[1]) <= 4 || std::strcmp(start_ptr, ".txt"))
        throw std::runtime_error("Error: Bad file format");
}
int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
        {
            throw std::runtime_error("Usage: ./btc file_to_open.txt");
        }

        check_file(argv);

        std::ifstream file(argv[1], std::ifstream::in); // open test?
        if (!file)
        {
            throw std::runtime_error("Error: Could not open file");
        }
        std::string line;
        while (getline(file, line))
            if (line.empty())
                throw std::runtime_error("Error: Empty line in input file.");
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::ifstream file2(argv[1], std::ifstream::in);

    BitcoinExchange btc(file2, argv);

    return 0;
}