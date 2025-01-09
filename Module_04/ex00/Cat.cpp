/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:35:31 by roko              #+#    #+#             */
/*   Updated: 2025/01/09 15:35:57 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat def constructor called with type: " << this->type << std::endl;
}
Cat::Cat(Cat const &other) : Animal(other.get_type())
{
	*this = other;
	std::cout << "Cat copy constructor called with type: " << this->type << std::endl;
}
Cat &Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
		this->type = other.get_type();
	}
	return (*this);
};
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}
void Cat::makeSound()
{
	std::cout << "Meow" << std::endl;
}