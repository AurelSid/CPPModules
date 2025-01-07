/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:28:48 by roko              #+#    #+#             */
/*   Updated: 2025/01/07 13:32:53 by roko             ###   ########.fr       */
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
	std::cout << this->_name << "attacks" << target << "for" << this->_attack_damage << "points" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Destructor called" << std::endl;
}
void ClapTrap::beReapaired(unsigned int amount)
{
	std::cout << "Destructor called" << std::endl;
}
std::string ClapTrap::get_name()
{
	return (this->_name);
}
int ClapTrap::get_hit_points(void)
{
	return (this->_hit_points);
}
int ClapTrap::get_energy_points(void)
{
	return (this->_energy_points);
}
int ClapTrap::get_attack_damage(void)
{
	return (this->_attack_damage);
}