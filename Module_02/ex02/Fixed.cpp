/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:00:24 by asideris          #+#    #+#             */
/*   Updated: 2025/01/06 18:21:26 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::~Fixed()
{
}
Fixed::Fixed() : fixed_point(0)
{
}
Fixed::Fixed(const Fixed &other) : fixed_point(other.fixed_point)
{
}
Fixed::Fixed(const int to_fixed)
{
	this->fixed_point = to_fixed << this->fraction;
}
Fixed::Fixed(const float to_fixed)
{
	this->fixed_point = roundf(to_fixed * (1 << fraction));
}
Fixed &Fixed::operator=(const Fixed &other)
{
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
	return (this->fixed_point);
}
void Fixed::setRawBits(int const raw)
{
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

	temp = *this;
	operator++();
	return (temp);
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
	return (temp);
}

bool Fixed::operator==(Fixed &other)
{
	if (this->fixed_point == other.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator>(Fixed const &other) const
{
	if (this->fixed_point > other.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator<(Fixed const &other) const
{
	if (this->fixed_point < other.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator<=(Fixed const &other) const
{
	if (this->fixed_point <= other.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator>=(Fixed const &other) const
{
	if (this->fixed_point >= other.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator!=(Fixed const &other) const
{
	if (this->fixed_point != other.getRawBits())
		return (1);
	return (0);
}
Fixed Fixed::operator+(Fixed const &other) const
{
	Fixed tmp(this->toFloat() + other.toFloat());
	return ((*this));
}
Fixed Fixed::operator-(Fixed const &other) const
{
	Fixed tmp(this->toFloat() - other.toFloat());
	return ((*this));
}
Fixed Fixed::operator/(Fixed const &other) const
{
	Fixed tmp(this->toFloat() / other.toFloat());
	return ((*this));
}
Fixed Fixed::operator*(Fixed const &other) const
{
	Fixed tmp(this->toFloat() * other.toFloat());
	return (tmp);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
