/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:13:33 by roko              #+#    #+#             */
/*   Updated: 2025/03/25 20:26:55 by roko             ###   ########.fr       */
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
#include <vector>
class BitcoinExchange
{
public:
    BitcoinExchange(std::ifstream &file, char **argv);
    ~BitcoinExchange();
    BitcoinExchange(BitcoinExchange &other);

    std::ifstream csv_file;

private:
    void _check_file_lines_format(std::ifstream &file);
    void _find_date(std::string data_str);
    void _find_price(std::string data_str);
    void _find_value(std::string data_str);
    void _merge_data_print();
    std::vector<float> _price_array;
    std::vector<std::string> _date_array;
    std::vector<float> _value_array;
};

#endif