/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:13:33 by roko              #+#    #+#             */
/*   Updated: 2025/03/26 17:58:34 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <map>
#include <vector>
#include <string>
class BitcoinExchange
{
public:
    BitcoinExchange(std::ifstream &file, char **argv);
    ~BitcoinExchange();
    BitcoinExchange(BitcoinExchange &other);

    std::ifstream csv_file;

private:
    void _check_file_lines_format(std::ifstream &file);
    int _find_date(std::string data_str);
    std::string _print_compose(std::string line);
    std::map<int, std::string> _sorted_array;
    int date_to_int(std::string line);
    void printSortedArray();
    std::string _closest_date(int date_int);
    void _fill_data_array();
    float get_price(std::string line);
    float get_wallet_price(std::string line);
    float get_volume();
    float get_closest_date_price(std::string line);
};

#endif