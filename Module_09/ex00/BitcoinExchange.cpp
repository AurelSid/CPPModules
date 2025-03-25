/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:42:38 by roko              #+#    #+#             */
/*   Updated: 2025/03/25 20:27:14 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream &file, char **argv)
{
    std::ifstream data;
    (void)argv;
    data.open("data.csv", std::ifstream::in);
    _check_file_lines_format(file);
    _merge_data_print();
}
BitcoinExchange ::~BitcoinExchange() {}

void BitcoinExchange::_check_file_lines_format(std::ifstream &file)
{
    std::string line;
    std::cout << "Checking lines format of input..." << std::endl;
    if (!getline(file, line))
    {
        std::cerr << "Error: File is empty or cannot be read." << std::endl;
        return;
    }
    while (getline(file, line))
    {
        char *cursor = &line[0];
        if (line.length() < 10)
        {
            std::cerr << "Error: Invalid line format (too short): " << line << std::endl;
            continue;
        }

        int year = atoi(line.substr(0, 4).c_str());
        if (year < 1000 || year > 9999)
        {
            std::cerr << "Error: Year is not a valid number: " << line << std::endl;
            exit(0);
        }
        if (std::strncmp(cursor + 10, " | ", 3))

        {
            std::cerr << "Error: Invalid date format, expected YYYY-MM-DD: " << line << std::endl;
            exit(0);
        }
        if (!isdigit(*(cursor + 6)) || !isdigit(*(cursor + 5)))
        {
            std::cerr << "Error: month is not the right format: " << line << std::endl;
            exit(0);
        }
        int month = atoi(line.substr(5, 2).c_str());
        if (month < 1 || month > 12)
        {
            std::cerr << "Error: month is not a valid number: " << month << "  " << line << std::endl;
            exit(0);
        }
        if (!isdigit(*(cursor + 8)) || !isdigit(*(cursor + 9)))
        {
            std::cerr << "Error: month is not the right format: " << line << std::endl;
            exit(0);
        }
        int day = atoi(line.substr(8, 2).c_str());
        if (day < 1 || day > 30)
        {
            std::cerr << "Error: day is not a valid number: " << day << "  " << line << std::endl;
            exit(0);
        }
        _find_date(line.substr(0, 10).c_str());
        _find_price(line.substr(0, 10).c_str());
        _find_value(line.substr(0, 10).c_str());
    }
}

void BitcoinExchange::_find_date(std::string data_str)
{
    std::string data_line;
    std::ifstream data_file("data.csv", std::ifstream::in);
    while (getline(data_file, data_line))
    {
        if (!std::strcmp((data_line.substr(0, 10).c_str()), data_str.c_str()))
        {
            _date_array.push_back(data_line.substr(0, 10));
            std::cout << "line found :" << data_line << std::endl;
        }
    }
}
void BitcoinExchange::_find_price(std::string data_str)
{
    float price;
    std::string data_line;
    std::ifstream data_file("data.csv", std::ifstream::in);
    while (getline(data_file, data_line))
    {
        if (!std::strcmp((data_line.substr(0, 10).c_str()), data_str.c_str()))
        {
            price = atof(data_line.substr(11, 20).c_str());
            std::cout << price << std::endl;
            _price_array.push_back(price);
        }
    }
}
void BitcoinExchange::_find_value(std::string data_str)
{
    float value;
    std::string data_line;
    std::ifstream data_file("data.csv", std::ifstream::in);
    while (getline(data_file, data_line))
    {
        if (!std::strcmp((data_line.substr(0, 10).c_str()), data_str.c_str()))
        {
            value = atof(data_line.substr(13, data_line.length()).c_str());
            std::cout << value << std::endl;
            _value_array.push_back(value);
        }
    }
}
void BitcoinExchange::_merge_data_print()
{
    std::vector<float>::iterator price_it = _price_array.begin();
    std::vector<std::string>::iterator date_it = _date_array.begin();
    std::vector<float>::iterator value_it = _value_array.begin();

    for (; date_it != _date_array.end() && price_it != _price_array.end() && value_it != _value_array.end();
         ++date_it, ++price_it, ++value_it)
    {
        std::cout << *date_it << " : " << *price_it << " : " << *value_it << std::endl;
    }
}
