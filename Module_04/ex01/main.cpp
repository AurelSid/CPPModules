/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:49:03 by babreton          #+#    #+#             */
/*   Updated: 2025/01/10 14:20:07 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal *array[100];
	int i = 0;

	while (i < 50)
		array[i++] = new Dog();
	while (i < 100)
		array[i++] = new Cat();

	array[4]->makeSound();
	array[72]->makeSound();
	for (i = 0; i < 100; i++)
		delete array[i];

	return (0);
}