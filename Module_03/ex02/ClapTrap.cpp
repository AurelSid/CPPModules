/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:28:48 by roko              #+#    #+#             */
/*   Updated: 2025/01/08 17:38:36 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "===================" << std::endl;
	std::cout << this->_name << " Constructor called" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &other)
{
	*this = other;
}
ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	if (this != &other)
	{
		this->_attack_damage = other.get_attack_damage();
		this->_hit_points = other.get_hit_points();
		this->_energy_points = other.get_energy_points();
	}
	return (*this);
}
ClapTrap::~ClapTrap()
{
	std::cout << "===================" << std::endl;
	std::cout << this->_name << " Clap was destroyed" << std::endl;
}
void ClapTrap::attack(const std::string &target)
{
	if (this->_hit_points > 0)
	{
		this->_energy_points -= 1;
		std::cout << "===================" << std::endl;
		std::cout << this->_name << " attacks " << target << " for " << this->_attack_damage << " points " << std::endl;
		std::cout << "Energy left: " << this->_energy_points << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points = this->_hit_points - amount;
	std::cout << "===================" << std::endl;
	std::cout << this->_name << " took damage "
				<< "remaining hit points: " << this->_hit_points << std::endl;
}
void ClapTrap::beReapaired(unsigned int amount)
{
	std::cout << this->_name << "is repaired for :" << amount << "points" << std::endl;
	this->_energy_points += amount;
}

///////////////// GETS

int ClapTrap::get_hit_points(void) const
{
	return (this->_hit_points);
}
int ClapTrap::get_energy_points(void) const
{
	return (this->_energy_points);
}
int ClapTrap::get_attack_damage(void) const
{
	return (this->_attack_damage);
}
std::string ClapTrap::get_name() const
{
	return (this->_name);
}

/////////////////////////////////// SETS

void ClapTrap::set_hit_points(int val)
{
	this->_hit_points = val;
}
void ClapTrap::set_energy_points(int val)
{
	this->_energy_points = val;
}
void ClapTrap::set_attack_damage(int val)
{
	this->_attack_damage = val;
}
void ClapTrap::set_name(std::string name)
{
	this->_name = name;
};
