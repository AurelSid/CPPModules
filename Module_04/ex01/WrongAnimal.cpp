/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:13:40 by roko              #+#    #+#             */
/*   Updated: 2025/01/09 15:36:47 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unknown"){};
WrongAnimal::~WrongAnimal()
{
	std::cout << this->type << " wrong animal def constructor called" << std::endl;
};
WrongAnimal::WrongAnimal(std::string const &type)
{
	this->type = type;
	std::cout << this->type << " Wrong Animal constructor called" << std::endl;
};
WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	std::cout << this->type << "Wrong animal copy constructor called" << std::endl;
	*this = other;
};

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	if (this != &other)
	{
		this->type = other.get_type();
	}
	return (*this);
};

std::string WrongAnimal::get_type() const
{
	return (this->type);
};

void WrongAnimal::set_type(std::string const type)
{
	this->type = type;
};
void WrongAnimal::makeSound()
{
	std::cout << "I AM A WEIIIIRD Animal" << std::endl;
}