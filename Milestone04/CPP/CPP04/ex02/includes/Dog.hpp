/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:28:26 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/04 11:55:10 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "../includes/AAnimal.hpp"
#include "../includes/Brain.hpp"
#include <string>

class Dog : public AAnimal
{
	private:
		::Brain* brain;
		
	public:
		Dog();
		Dog(const Dog& dog);
		~Dog();
		Dog& operator=(const Dog& dog);
		void makeSound() const; 	
};

#endif