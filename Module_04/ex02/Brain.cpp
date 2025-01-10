/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:20:13 by roko              #+#    #+#             */
/*   Updated: 2025/01/09 23:09:13 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Def Bain constructor called" << std::endl;
};
Brain::~Brain()
{
	std::cout << "Def Bain destroyer called" << std::endl;
}
Brain::Brain(Brain const &other)
{
	std::cout << " Bain copy constructor called" << std::endl;
	*this = other;
};
Brain &Brain::operator=(Brain const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
};