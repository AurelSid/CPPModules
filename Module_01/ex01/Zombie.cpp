/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:51:00 by roko              #+#    #+#             */
/*   Updated: 2025/01/02 12:43:50 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string Zombie::get_name()
{
	return (this->name);
}

void Zombie::announce(void)
{
	std::cout << this->get_name() << ": BraiiiiiiinnnzzzzZ." << std::endl;
}
Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->get_name() << " is destroyed." << std::endl;
}
void Zombie::Zombie_name(std::string name)
{
	this->name = name;
}
