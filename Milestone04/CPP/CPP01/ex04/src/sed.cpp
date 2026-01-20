/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:53:27 by drubio-s          #+#    #+#             */
/*   Updated: 2026/01/20 19:10:53 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sed.hpp"
#include <iostream>
#include <string>
#include <fstream>

int	sed(const std::string& FileIn, const std::string& Word1, const std::string& Word2)
{
	std::string FileOut = FileIn + ".replace";
	std::ifstream	ReadFile(FileIn.c_str());
	std::string	buffer;

	size_t	size1 = Word1.size();
	size_t	size2 = Word2.size();
	if (ReadFile.is_open() && !ReadFile.fail())
	{
		std::ofstream	WriteFile(FileOut.c_str());
		if(WriteFile.is_open() && !WriteFile.fail())
		{
			while(std::getline(ReadFile, buffer))
			{
				size_t	pos1 = 0;
				while(1)
				{
					size_t pos = buffer.find(Word1, pos1);
					if (pos != std::string::npos)
					{
						buffer.erase(pos, size1);
						buffer.insert(pos, Word2);
						pos1 = (pos + size2);
					}
					else
						break;
				}
				WriteFile << buffer << "\n";
			}
			WriteFile.close();
		}
		else
		{
			std::cerr << "Failed to open/create write file" << std::endl;
			return (1);
		}
		ReadFile.close();
	}
	else
	{
		std::cerr << "Failed to open/read the read file" << std::endl;
		return (1);
	}
	return (0);
}
