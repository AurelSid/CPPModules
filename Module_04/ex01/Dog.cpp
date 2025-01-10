/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:35:31 by roko              #+#    #+#             */
/*   Updated: 2025/01/10 15:20:56 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog def constructor called with type: " << this->type << std::endl;
	this->brain = new Brain;
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
		for (int i; i < 100; i--)
			this->brain[i] = other.brain[i];
	}
	return (*this);
};
Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}
void Dog::makeSound()
{
	std::cout << this->type << "Makes : WOOF" << std::endl;
}