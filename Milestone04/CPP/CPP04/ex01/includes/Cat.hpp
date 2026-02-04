/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:28:23 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/04 10:17:01 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"
#include <string>

class Cat : public Animal
{
	private:
		::Brain* brain;
		
	public:
		Cat();
		Cat(const Cat& cat);
		~Cat();
		Cat& operator=(const Cat& cat);
		void makeSound() const;
};
#endif