/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:35:31 by roko              #+#    #+#             */
/*   Updated: 2025/01/10 15:21:21 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat def constructor called with type: " << this->type << std::endl;
	this->brain = new Brain;
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
		this->type = other.get_type();
		for (int i; i < 100; i--)
			this->brain[i] = other.brain[i];
	}
	return (*this);
};
Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}
void Cat::makeSound()
{
	std::cout << this->type << "Makes : Meow" << std::endl;
}