/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:04:33 by drubio-s          #+#    #+#             */
/*   Updated: 2025/12/19 10:32:08 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int	main(int argc, char **argv)
{	
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			if (i != 1)
				std::cout << " ";
			std::string  input = argv[i];
			for(size_t j = 0; j < input.size(); j++)
				std::cout << (char)std::toupper((unsigned char)input[j]);
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
	return (0);
}
