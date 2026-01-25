/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:34:39 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/25 12:12:29 by drubio-s         ###   ########.fr       */
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
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed(const int n);
		Fixed(const float n);
		~Fixed();
		Fixed& operator=(const Fixed& fixed);
		float toFloat() const;
		int	toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
#endif