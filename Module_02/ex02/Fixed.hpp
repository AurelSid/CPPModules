/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:51:00 by roko              #+#    #+#             */
/*   Updated: 2025/01/04 16:48:50 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_H
# define Fixed_H

# include <iostream>
# include <math.h>
# include <unistd.h>

class Fixed
{
  public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int to_fixed);
	Fixed(const float to_fixed);

	Fixed &operator=(const Fixed &other);

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	bool operator==(Fixed &other);
	bool operator>(Fixed const &other) const;
	bool operator<(Fixed const &other) const;
	bool operator<=(Fixed const &other) const;
	bool operator>=(Fixed const &other) const;
	bool operator!=(Fixed const &other) const;

	Fixed operator+(Fixed const &other) const;
	Fixed operator-(Fixed const &other) const;
	Fixed operator/(Fixed const &other) const;
	Fixed operator*(Fixed const &other) const;

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);

	static const Fixed &min(Fixed const &a, Fixed const &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
	~Fixed();

  private:
	int fixed_point;
	static const int fraction = 8;
};
std::ostream &operator<<(std::ostream &o, Fixed const &obj);
#endif