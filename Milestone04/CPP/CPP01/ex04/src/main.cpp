/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:20:24 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/20 19:06:12 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/sed.hpp"

int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "The number of parameters is incorrect" << std::endl;
		return (1);
	}
	else
	{
		const std::string FileIn = argv[1];
		const std::string	Word1 = argv[2];
		const std::string Word2 = argv[3];
		if (Word1.empty())
		{
			std::cerr << "The first word cannot be empty" << std::endl;
			return (1);
		}
		return(sed(FileIn, Word1, Word2));
	}
}