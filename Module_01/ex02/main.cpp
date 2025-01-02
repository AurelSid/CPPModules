/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:26:20 by asideris          #+#    #+#             */
/*   Updated: 2025/01/02 13:48:18 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>

int	main(void)
{
	std::string str;
	std::string *str_ptr;
	std::string &str_ref = str;
	str_ptr = &str;

	str = "HI THIS IS BRAIN";

	std::cout << &str << std::endl;
	std::cout << str_ptr << std::endl;
	std::cout << &str_ref << std::endl;

	std::cout << str << std::endl;
	std::cout << *str_ptr << std::endl;
	std::cout << str_ref << std::endl;
	return (0);
}