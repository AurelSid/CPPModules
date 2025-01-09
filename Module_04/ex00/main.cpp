/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:49:03 by babreton          #+#    #+#             */
/*   Updated: 2025/01/09 15:49:33 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// WrongAnimal *unknown = new WrongAnimal();
	Dog *dog = new Dog();

	// std::cout << unknown->getType() << " " << std::endl;
	std::cout << dog->get_type() << " " << std::endl;

	// unknown->makeSound();
	dog->makeSound();
	// delete unknown;

	// unknown = new WrongCat();
	// unknown->makeSound();
	delete dog;
	// delete unknown;
}