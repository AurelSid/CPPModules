/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:08:38 by roko              #+#    #+#             */
/*   Updated: 2025/01/09 13:15:28 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->set_name(name);
	this->set_attack_damage(30);
	this->set_energy_points(100);
	this->set_hit_points(100);
	std::cout << "An evil FragTrap appear,"
				<< ":" << this->get_name() << " he has: " << this->get_attack_damage() << " attack damage !" << std::endl;
};
FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other.get_name())
{
	*this = other;
};
FragTrap::~FragTrap()
{
	std::cout << "====================" << std::endl;
	std::cout << this->_name << " was destroyed " << std::endl;
};
FragTrap &FragTrap::operator=(FragTrap const &other)
{
	this->_name = other.get_name();
	this->_attack_damage = other.get_attack_damage();
	this->_energy_points = other.get_energy_points();
	this->_hit_points = other.get_hit_points();
	return (*this);
}
void FragTrap::attack(const std::string &target)
{
	if (this->get_hit_points() > 0)
	{
		this->set_hit_points(this->get_hit_points() - 1);
		std::cout << "===================" << std::endl;
		std::cout << this->_name << " attacks " << target << " for " << this->_attack_damage << " points " << std::endl;
		std::cout << "Energy left: " << this->_energy_points << std::endl;
	}
};
void FragTrap::guardGate(void)
{
	std::cout << this->_name << "is in gatekeep mode!" << std::endl;
};
void FragTrap::highFiveGuys(void)
{
	std::cout << "Give me a high five guys!" << std::endl;
};
