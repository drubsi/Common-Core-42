/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:47:18 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/22 10:31:30 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <iostream>

Harl::Harl()
{
}
void Harl::debug()
{
	std::cout << "[ DEBUG ]\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}
void Harl::info()
{
	std::cout << "[ INFO ]\n" << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}
void Harl::warning()
{
		std::cout << "[ WARNING ]\n" << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
}
void Harl::error()
{
	std::cout << "[ ERROR ]\n" << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}
void Harl::complain(std::string level)
{
	std::string HarlLevel[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;

	for(i = 0; i < 4; i++)
	{
		if (HarlLevel[i] != level)
			continue;
		else
			break;
	}
	switch (i)
	{
		case 0:
		{
			debug();
			info();
			warning();
			error();
			break;
		}
		case 1:
		{
			info();
			warning();
			error();
			break;
		}
		case 2:
		{
			warning();
			error();
			break;
		}
		case 3:
		{
			error();
			break;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}