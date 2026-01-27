/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:54:13 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/27 02:05:59 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
	
	private:
		int						fixedPointValue;
		static const int		fractionalBits;
		
	public:
		//CONSTRUCTORS
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed(const int n);
		Fixed(const float n);
		//DESTRUCTOR
		~Fixed();
		//OPERATORS
			//COPY ASSIGNMENT
		Fixed& operator=(const Fixed& fixed);
			//ARITHMETIC
		Fixed operator+(const Fixed& fixed) const;
		Fixed operator-(const Fixed& fixed) const;
		Fixed operator*(const Fixed& fixed) const;
		Fixed operator/(const Fixed& fixed) const;
			//COMPARISON
		bool operator>(const Fixed& fixed) const;
		bool operator<(const Fixed& fixed) const;
		bool operator>=(const Fixed& fixed) const;
		bool operator<=(const Fixed& fixed) const;
		bool operator==(const Fixed& fixed) const;
		bool operator!=(const Fixed& fixed) const;
			//INCREMENT
		Fixed& operator++();
		Fixed operator++(int);
			//DECREMENT
		Fixed& operator--();
		Fixed operator--(int);
		//MEMBER FUNCTIONS
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat() const;
		int	toInt(void) const;
		static Fixed& min(Fixed& fixedPointA, Fixed& fixedPointB);
		static const Fixed& min(const Fixed& fixedPointA, const Fixed& fixedPointB);
		static Fixed& max(Fixed& fixedPointA, Fixed& fixedPointB);
		static const Fixed& max(const Fixed& fixedPointA, const Fixed& fixedPointB);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
#endif