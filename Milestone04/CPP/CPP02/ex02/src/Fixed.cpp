/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:53:46 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/27 02:15:34 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Fixed.hpp"
#include <cmath>

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPointValue(0)
{
}
Fixed::Fixed(const int n) : fixedPointValue(n << fractionalBits)
{
}
Fixed::Fixed(const float n)
{
	const int scale = (1 << fractionalBits);
	fixedPointValue = static_cast<int>(roundf(n * scale));
}
Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}
Fixed::~Fixed()
{
}
Fixed& Fixed::operator=(const Fixed& fixed)
{
	if (this != &fixed)
		this->fixedPointValue = fixed.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed res;
	
	res.fixedPointValue = this->fixedPointValue + fixed.fixedPointValue;
	return (res);
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed res;
	res.fixedPointValue = this->fixedPointValue - fixed.fixedPointValue;
	return (res);
}

Fixed Fixed::operator*(const Fixed& fixed) const 
{
	Fixed res;

	const int scale = (1 << fractionalBits);
	
	res.fixedPointValue = ((static_cast<long long>(this->fixedPointValue) * fixed.fixedPointValue) / scale);
	return (res);
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	Fixed res;

	const int scale = (1 << fractionalBits);
	if (fixed.fixedPointValue != 0)
	{
		res.fixedPointValue = ((static_cast<long long>(this->fixedPointValue) * scale) / fixed.fixedPointValue);
	}
	return (res);
}

bool Fixed::operator>(const Fixed& fixed) const
{
	return (this->fixedPointValue > fixed.fixedPointValue);
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return (this->fixedPointValue < fixed.fixedPointValue);
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return (this->fixedPointValue >= fixed.fixedPointValue);
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return (this->fixedPointValue <= fixed.fixedPointValue);
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return (this->fixedPointValue == fixed.fixedPointValue);
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return (this->fixedPointValue != fixed.fixedPointValue);
}

Fixed& Fixed::operator++()
{
	this->fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp(*this);
	this->fixedPointValue++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->fixedPointValue --;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	
	this->fixedPointValue--;
	return (temp);
}
//-----------------------------------------------------------//
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
int	Fixed::getRawBits() const
{
	return (fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}
float Fixed::toFloat() const
{
	const int scale = (1 << fractionalBits);
    return (static_cast<float>(fixedPointValue) / static_cast<float>(scale));
}

int	Fixed::toInt() const
{
	return (fixedPointValue >> fractionalBits);
}

Fixed& Fixed::min(Fixed& fixedPointA, Fixed& fixedPointB)
{
	return ((fixedPointA.fixedPointValue < fixedPointB.fixedPointValue)? fixedPointA : fixedPointB);
}
const Fixed& Fixed::min(const Fixed& fixedPointA, const Fixed& fixedPointB)
{
	return ((fixedPointA.fixedPointValue < fixedPointB.fixedPointValue)? fixedPointA : fixedPointB);
}
Fixed& Fixed::max(Fixed& fixedPointA, Fixed& fixedPointB)
{
	return ((fixedPointA.fixedPointValue > fixedPointB.fixedPointValue)? fixedPointA : fixedPointB);
}
const Fixed& Fixed::max(const Fixed& fixedPointA, const Fixed& fixedPointB)
{
	return ((fixedPointA.fixedPointValue > fixedPointB.fixedPointValue)? fixedPointA : fixedPointB);
}

