/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:42:38 by roko              #+#    #+#             */
/*   Updated: 2025/03/26 18:20:01 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream &file, char **argv)
{
    std::ifstream data;
    (void)argv;
    data.open("data.csv", std::ifstream::in);
    _fill_data_array();
    _check_file_lines_format(file);
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
            std::cout << "Error: Invalid line format (too short): " << line << std::endl;
            continue;
        }

        int year = atoi(line.substr(0, 4).c_str());
        if (year < 1000 || year > 9999)
        {
            std::cout << "Error: Year is not a valid number: " << line << std::endl;
            continue;
        }

        if (std::strncmp(cursor + 10, " | ", 3))
        {
            std::cout << "Error: Invalid date format, expected YYYY-MM-DD: " << line << std::endl;
            continue;
        }

        if (!isdigit(*(cursor + 6)) || !isdigit(*(cursor + 5)))
        {
            std::cout << "Error: Month is not in the right format: " << line << std::endl;
            continue;
        }

        int month = atoi(line.substr(5, 2).c_str());
        if (month < 1 || month > 12)
        {
            std::cout << "Error: Month is not a valid number: " << line << std::endl;
            continue;
        }

        if (!isdigit(*(cursor + 8)) || !isdigit(*(cursor + 9)))
        {
            std::cout << "Error: Day is not in the right format: " << line << std::endl;
            continue;
        }

        int day = atoi(line.substr(8, 2).c_str());
        if (day < 1 || day > 30)
        {
            std::cout << "Error: Day is not a valid number: " << line << std::endl;
            continue;
        }
        long volume = atol(line.substr(13, (line.length() - 13)).c_str());
        if (volume >= __INT_MAX__)
        {
            std::cout << "Error: Volume too big: " << line << std::endl;
            continue;
        }
        if (volume < 0)
        {
            std::cout << "Error: Negative wallet not valid: " << line << std::endl;
            continue;
        }

        if (_find_date(line))
        {
            std::cout << line << "| Price : " << get_price(line)
                      << "| Wallet Value : " << get_wallet_price(line) << std::endl;
            date_to_int(line);
        }
        else
        {
            std::cout << "Closest date: " << _closest_date(date_to_int(line))
                      << " | Volume : "
                      << atof(line.substr(13, (line.length() - 13)).c_str())
                      << " | Price : "
                      << get_closest_date_price(line)
                      << " | Wallet Value :" << atof(line.substr(13, (line.length() - 13)).c_str()) * get_closest_date_price(line)
                      << std::endl;
        }
    }
}

int BitcoinExchange::_find_date(std::string data_str)
{
    std::string data_line;
    std::ifstream data_file("data.csv", std::ifstream::in);
    while (getline(data_file, data_line))
    {
        if (data_line.substr(0, 10) == data_str.substr(0, 10))

            return (1);
    }
    return (0);
}
int BitcoinExchange::date_to_int(std::string line)
{
    int date = atoi(line.substr(0, 4).c_str()) * 10000 +
               atoi(line.substr(5, 2).c_str()) * 100 +
               atoi(line.substr(8, 2).c_str());
    return date;
}
void BitcoinExchange::_fill_data_array()
{
    std::string data_line;
    std::ifstream data_file("data.csv", std::ifstream::in);
    while (getline(data_file, data_line))

        _sorted_array[date_to_int(data_line)] = data_line.substr(0, 10).c_str();
}
void BitcoinExchange::printSortedArray()
{
    std::cout << "==============" << std::endl;
    std::map<int, std::string>::iterator it;
    for (it = _sorted_array.begin(); it != _sorted_array.end(); ++it)
    {
        std::cout << "Date (int): " << it->first << ", Value: " << it->second << std::endl;
    }
}
std::string BitcoinExchange::_closest_date(int data_int)
{
    std::map<int, std::string>::iterator it;
    while (_sorted_array.find(data_int) == _sorted_array.end())
    {
        --data_int;
    }
    return _sorted_array[data_int];
}
float BitcoinExchange::get_price(std::string line)
{
    float price;
    std::string data_line;
    std::ifstream data_file("data.csv", std::ifstream::in);
    while (getline(data_file, data_line))
    {
        if (data_line.substr(0, 10) == line.substr(0, 10))
            price = atof(data_line.substr(11, (data_line.length() - 11)).c_str());
    }

    return price;
}

float BitcoinExchange::get_wallet_price(std::string line)
{
    float wallet_value = get_price(line) * atof(line.substr(13, (line.length() - 13)).c_str());
    return wallet_value;
}
float BitcoinExchange::get_closest_date_price(std::string line)
{
    int date_int = date_to_int(line);
    std::string closest = _closest_date(date_int);
    float price = get_price(closest);
    return price;
}
