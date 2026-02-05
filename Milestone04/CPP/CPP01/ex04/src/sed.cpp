/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:53:27 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:11:20 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"
#include <iostream>
#include <string>
#include <fstream>

int	sed(const std::string& fileIn, const std::string& word1, const std::string& word2)
{
	std::string fileOut = fileIn + ".replace";
	std::ifstream	readFile(fileIn.c_str());
	std::string	buffer;

	size_t	size1 = word1.size();
	size_t	size2 = word2.size();
	if (readFile.is_open() && !readFile.fail())
	{
		std::ofstream	writeFile(fileOut.c_str());
		if(writeFile.is_open() && !writeFile.fail())
		{
			while(std::getline(readFile, buffer))
			{
				size_t	pos1 = 0;
				while(1)
				{
					size_t pos = buffer.find(word1, pos1);
					if (pos != std::string::npos)
					{
						buffer.erase(pos, size1);
						buffer.insert(pos, word2);
						pos1 = (pos + size2);
					}
					else
						break;
				}
				writeFile << buffer << "\n";
			}
			writeFile.close();
		}
		else
		{
			std::cerr << "Failed to open/create write file" << std::endl;
			return (1);
		}
		readFile.close();
	}
	else
	{
		std::cerr << "Failed to open/read the read file" << std::endl;
		return (1);
	}
	return (0);
}
