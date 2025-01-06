/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:00:24 by asideris          #+#    #+#             */
/*   Updated: 2025/01/06 16:30:27 by roko             ###   ########.fr       */
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

Fixed &Fixed::operator++()
{
	this->fixed_point++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed	temp;

	operator++();
	temp = *this;
}
Fixed &Fixed::operator--()
{
	this->fixed_point--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed	temp;

	operator--();
	temp = *this;
}

bool Fixed::operator==(Fixed &other)
{
	if (this->fixed_point == other.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator>(Fixed &other)
{
	if (this->fixed_point > other.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator<(Fixed &other)
{
	if (this->fixed_point < other.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator<=(Fixed &other)
{
	if (this->fixed_point <= other.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator>=(Fixed &other)
{
	if (this->fixed_point >= other.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator!=(Fixed &other)
{
	if (this->fixed_point != other.getRawBits())
		return (1);
	return (0);
}
Fixed Fixed::operator+(Fixed &other)
{
	Fixed tmp(this->toFloat() + other.toFloat());
	return ((*this));
}
Fixed Fixed::operator-(Fixed &other)
{
	Fixed tmp(this->toFloat() - other.toFloat());
	return ((*this));
}
Fixed Fixed::operator/(Fixed &other)
{
	Fixed tmp(this->toFloat() / other.toFloat());
	return ((*this));
}
Fixed Fixed::operator*(Fixed const &other)
{
	Fixed tmp(this->toFloat() * other.toFloat());
	return ((*this));
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
