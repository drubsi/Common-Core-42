/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:00:33 by drubio-s          #+#    #+#             */
/*   Updated: 2025/12/29 11:21:35 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : nextIndex(0), count(0)
{
	return ;
}
PhoneBook::~PhoneBook(void)
{
}
int PhoneBook::getCount() const
{
	return count;
}

void PhoneBook::addContact(const Contact& c)
{
	contacts[nextIndex] = c;
	if (count < 8)
		count++;
	nextIndex = (nextIndex + 1) % 8;
}

void PhoneBook::displayContacts() const
{
	if (count == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	std::cout << std::setw(10) <<"Index" << "|"
			<< std::setw(10) << "FirstName" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < count; i++)
		contacts[i].displaySummary(i);
}

void PhoneBook::displayContactByIndex(int index) const
{
	if (index < 0 || index >= 8)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	if (!contacts[index].isValid())
	{
		std::cout << "Empty contact." << std::endl;
		return ;
	}
	contacts[index].displayFull();
}
