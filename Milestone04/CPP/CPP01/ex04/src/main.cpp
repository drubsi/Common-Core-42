/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:20:24 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:11:14 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "sed.hpp"

int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "The number of parameters is incorrect" << std::endl;
		return (1);
	}
	else
	{
		const std::string fileIn = argv[1];
		const std::string	word1 = argv[2];
		const std::string word2 = argv[3];
		if (word1.empty())
		{
			std::cerr << "The first word cannot be empty" << std::endl;
			return (1);
		}
		return(sed(fileIn, word1, word2));
	}
}