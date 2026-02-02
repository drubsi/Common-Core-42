/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:28:16 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/02 11:53:48 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define	ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string type;
	
	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& animal);
		Animal& operator=(const Animal& animal);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const;
};

#endif