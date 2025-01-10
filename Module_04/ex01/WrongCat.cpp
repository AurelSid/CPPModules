/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:35:31 by roko              #+#    #+#             */
/*   Updated: 2025/01/09 15:39:36 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat def constructor called with type: " << this->type << std::endl;
}
WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other.get_type())
{
	*this = other;
	std::cout << "WrongCat copy constructor called with type: " << this->type << std::endl;
}
WrongCat &WrongCat::operator=(WrongCat const &other)
{
	if (this != &other)
	{
		this->type = other.get_type();
	}
	return (*this);
};
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}
