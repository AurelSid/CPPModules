/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:28:48 by roko              #+#    #+#             */
/*   Updated: 2025/01/07 12:34:20 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name)
{
	std::cout << "Constructor called" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
void ClapTrap::attack(const std::string &target)
{
	std::cout << "Destructor called" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Destructor called" << std::endl;
}
void ClapTrap::beReapaired(unsigned int amount)
{
	std::cout << "Destructor called" << std::endl;
}