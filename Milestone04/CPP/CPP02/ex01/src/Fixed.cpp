/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:34:42 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/25 12:14:37 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <cmath>
#include <iostream>

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int n) : fixedPointValue(n << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	const int scale = (1 << fractionalBits);
	fixedPointValue = static_cast<int>(roundf(n * scale));
}
Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixedPointValue = fixed.getRawBits();
	return (*this);
}
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
float Fixed::toFloat() const
{
	const int scale = (1 << fractionalBits);
    return static_cast<float>(fixedPointValue) / static_cast<float>(scale);
}

int	Fixed::toInt() const
{
	return (fixedPointValue >> fractionalBits);
}

int	Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}
