/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:19:01 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/04 19:36:25 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "PhoneBook.hpp"

static bool readField(const char* prompt, std::string& out)
{
    std::cout << prompt;
    if (!std::getline(std::cin, out))
        return false;
    if (out.empty())
        return false;
    return true;
}

static void handleAdd(PhoneBook& pb)
{
	Contact c;
	std::string	first, last, nick, num, dark;
	
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (!readField("First Name: ", first) ||
        !readField("Last Name: ", last) ||
        !readField("Nickname: ", nick) ||
        !readField("Phone Number: ", num) ||
        !readField("Darkest secret: ", dark))
    {
        std::cout << "All fields must be non-empty." << std::endl;
        return;
    }

	c.setContact(first, last, nick, num, dark);
	pb.addContact(c);
}

static void handleSearch(const PhoneBook& pb)
{
	int	index;
	
	pb.displayContacts();
	if (pb.getCount() == 0)
		return;
	std::cout << "Index: ";
	if (!(std::cin >> index))
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input." << std::endl;
		return;
	}
	pb.displayContactByIndex(index);
}
int	main()
{
	PhoneBook phoneBook;
	std::string cmd;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!(std::cin >> cmd))
			break;
		if (cmd == "ADD")
			handleAdd(phoneBook);
		else if (cmd == "SEARCH")
			handleSearch(phoneBook);
		else if (cmd == "EXIT")
			break;
	}
	return (0);
}