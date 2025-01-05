/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:00:24 by asideris          #+#    #+#             */
/*   Updated: 2025/01/05 18:57:51 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed() : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other) : fixed_point(other.fixed_point)
{
	std::cout << "copy constructor called" << std::endl;
}
Fixed::Fixed(const int to_fixed)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = to_fixed << this->fraction;
}
Fixed::Fixed(const float to_fixed)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(to_fixed * (1 << fraction));
}
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&other == this)
		return (*this);
	else
	{
		this->setRawBits(other.getRawBits());
		return (*this);
	}
}
float Fixed::toFloat(void) const
{
	return ((float)this->fixed_point / (float)(1 << fraction));
}
int Fixed::toInt(void) const
{
	return ((int)this->fixed_point >> fraction);
}
std::ostream &operator<<(std::ostream &stream, Fixed const &obj)
{
	stream << obj.toFloat();
	return (stream);
}
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point);
}
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point = raw;
}
