/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:08:38 by roko              #+#    #+#             */
/*   Updated: 2025/01/08 17:34:11 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap()
{
	this->set_name(name);
	this->set_attack_damage(20);
	this->set_energy_points(50);
	this->set_hit_points(100);
	std::cout << "An evil ScavTrap appear,"
				<< ":" << this->get_name() << " he has: " << this->get_attack_damage() << " attack damage !" << std::endl;
};
ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other.get_name())
{
	*this = other;
};
ScavTrap::~ScavTrap()
{
	std::cout << "====================" << std::endl;
	std::cout << this->_name << " was destroyed " << std::endl;
};
ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	this->_name = other.get_name();
	this->_attack_damage = other.get_attack_damage();
	this->_energy_points = other.get_energy_points();
	this->_hit_points = other.get_hit_points();
	return (*this);
}
void ScavTrap::attack(const std::string &target)
{
	if (this->get_hit_points() > 0)
	{
		this->set_hit_points(this->get_hit_points() - 1);
		std::cout << "===================" << std::endl;
		std::cout << this->_name << " attacks " << target << " for " << this->_attack_damage << " points " << std::endl;
		std::cout << "Energy left: " << this->_energy_points << std::endl;
	}
};
void ScavTrap::guardGate(void)
{
	std::cout << this->_name << "is in gatekeep mode!" << std::endl;
};
