/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:47:22 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/22 10:13:51 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <iostream>
#include <cctype>

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		Harl harl;
		std::string level = argv[1];
		
		for(size_t i = 0; i < level.length(); i++)
			level[i] = toupper(level[i]);
		harl.complain(level);	
	}
	else
	{
		std::cerr << "Please the program needs you to pass it an argument" << std::endl;
		return (1);
	}
	return (0);
}