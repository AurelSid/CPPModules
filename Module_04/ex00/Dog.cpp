/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:35:31 by roko              #+#    #+#             */
/*   Updated: 2025/01/09 15:39:36 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog def constructor called with type: " << this->type << std::endl;
}
Dog::Dog(Dog const &other) : Animal(other.get_type())
{
	*this = other;
	std::cout << "Dog copy constructor called with type: " << this->type << std::endl;
}
Dog &Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		this->type = other.get_type();
	}
	return (*this);
};
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}
void Dog::makeSound()
{
	std::cout << "Meow" << std::endl;
}