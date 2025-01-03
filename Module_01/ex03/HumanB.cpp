/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:51:00 by roko              #+#    #+#             */
/*   Updated: 2025/01/02 18:52:13 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

std::string HumanB::get_weapon_type(void)
{
	const std::string &weapon_type = this->weapon->get_type();
	return (weapon_type);
}
void HumanB::set_name(std::string name)
{
	this->name = name;
}

void HumanB::attack(void)
{
	std::cout << this->name << " "
				<< "attacks with"
				<< " " << this->get_weapon_type() << std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
