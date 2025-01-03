/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:12:49 by asideris          #+#    #+#             */
/*   Updated: 2025/01/03 15:09:15 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

void	replace_line(std::string from, std::string to, std::string line)
{
	size_t	starting_pos;
	size_t	found_pos;

	std::string replaced;
	starting_pos = 0;
	found_pos = 0;
	while (1)
	{
		if ((found_pos = line.find(from, starting_pos)) == std::string::npos)
			break ;
		replaced.append(line, starting_pos, found_pos - starting_pos);
		replaced.append(to);
		std::cout << replaced << std::endl;
		starting_pos = found_pos + from.length();
	}
	replaced.append(line, starting_pos, found_pos - starting_pos);
	std::cout << "Replaced line: " << replaced << std::endl;
}
int	main(int argc, char **argv)
{
	std::string replace_filename;
	std::string original_filename;
	std::fstream original_file;
	std::fstream file_replace;
	std::string curr_line;
	if (argc != 4)
		return (1);
	original_filename = argv[1];
	std::cout << original_filename << std::endl;
	replace_filename = original_filename + ".replace";
	std::cout << replace_filename << std::endl;
	original_file.open(original_filename, std::ios::in);
	if (original_file.fail())
		return (std::cerr << "Error: fail to open original file!" << std::endl,
			1);
	else
	{
		while (getline(original_file, curr_line))
		{
			std::cout << "treating : " << curr_line << std::endl;
			replace_line(argv[2], argv[3], curr_line);
		}
	}
	return (0);
}
