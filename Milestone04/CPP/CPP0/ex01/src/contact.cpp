/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:00:40 by drubio-s          #+#    #+#             */
/*   Updated: 2025/12/29 11:18:23 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/contact.hpp"
#include <iostream>
#include <iomanip>

static std::string formatField(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return std::string(10 - str.length(), ' ') + str;
}
Contact::Contact()
{
}

void Contact::setContact(const std::string& first,
						const std::string& last,
						const std::string& nick,
						const std::string& num,
						const std::string& dark)
{
	firstName = first;
	lastName = last;
	nickname = nick;
	phoneNumber = num;
	darkestSecret = dark;
}

bool Contact::isValid() const
{
	return (!firstName.empty()
			&& !lastName.empty()
			&& !nickname.empty()
			&& !phoneNumber.empty()
			&& !darkestSecret.empty());
}

void Contact::displaySummary(int index) const
{
	std::cout << std::setw(10) << index << "|"
			<< formatField(firstName) << "|"
			<< formatField(lastName) << "|"
			<< formatField(nickname) << std::endl;
}

void Contact::displayFull() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}