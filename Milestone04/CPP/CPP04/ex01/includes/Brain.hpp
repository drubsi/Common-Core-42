/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:05:10 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/04 10:01:05 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain 
{
	private:
		std::string ideas[100];
	
	public:
		Brain();
		Brain(const Brain& brain);
		~Brain();
		Brain& operator=(const Brain& brain);
		
};
#endif