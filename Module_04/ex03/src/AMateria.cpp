/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:13:17 by roko              #+#    #+#             */
/*   Updated: 2025/01/10 17:12:26 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Materia def construtor called" << std::endl;
}
AMateria::AMateria(AMateria &other)
{
	if (this != &other)
	{
		std::cout << "Materia copy construtor called" << std::endl;
		this->type = other.getType();
	}
}
AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "Materia def construtor called" << std::endl;
}
