/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:30:17 by roko              #+#    #+#             */
/*   Updated: 2025/01/10 19:30:08 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice def constructor called" << std ::endl;
}
Ice::Ice(Ice &other)
{
	*this = other;
	std::cout << "Ice copy constructor called" << std ::endl;
}
Ice::~Ice()
{
	std::cout << "Ice deconstructor called" << std ::endl;
}
AMateria *Ice::clone(void) const
{
	AMateria *newIce;

	newIce = new Ice;
	std::cout << "cloned Ice obj" << std::endl;
	return (newIce);
}
void Ice::use(ICharacter &target)
{
	std::cout << "*shoots ice bolt at " << target.getName() << std::endl;
}

Ice &Ice::operator=(Ice &other)
{
	if (this != &other)
	{
		this->type = other.getType();
	}
	return (*this);
}