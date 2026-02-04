/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:28:16 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/04 11:52:43 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define	AANIMAL_HPP

#include <string>

class AAnimal
{
	protected:
		std::string type;
	
	public:
		AAnimal();
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& Aanimal);
		AAnimal& operator=(const AAnimal& Aanimal);
		virtual ~AAnimal();
		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif