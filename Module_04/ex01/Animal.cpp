/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:13:40 by roko              #+#    #+#             */
/*   Updated: 2025/01/09 23:41:20 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << this->type << " def constructor called" << std::endl;
};
Animal::~Animal()
{
	std::cout << this->type << " def destructor called" << std::endl;
};
Animal::Animal(std::string const &type)
{
	this->type = type;
	std::cout << this->type << " constructor called" << std::endl;
};
Animal::Animal(Animal const &other)
{
	std::cout << this->type << " copy constructor called" << std::endl;
	*this = other;
};

Animal &Animal::operator=(Animal const &other)
{
	if (this != &other)
	{
		this->type = other.get_type();
	}
	return (*this);
};

std::string Animal::get_type() const
{
	return (this->type);
};

void Animal::set_type(std::string const type)
{
	this->type = type;
};

void Animal::makeSound(void)
{
	std::cout << "Im not dog and no cat the sound i make is sljdhfdshfds" << std::endl;
};