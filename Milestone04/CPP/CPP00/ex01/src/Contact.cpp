/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:00:40 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/04 19:19:56 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
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
	nickName = nick;
	phoneNumber = num;
	darkestSecret = dark;
}

bool Contact::isValid() const
{
	return (!firstName.empty()
			&& !lastName.empty()
			&& !nickName.empty()
			&& !phoneNumber.empty()
			&& !darkestSecret.empty());
}

void Contact::displaySummary(int index) const
{
	std::cout << std::setw(10) << index << "|"
			<< formatField(firstName) << "|"
			<< formatField(lastName) << "|"
			<< formatField(nickName) << std::endl;
}

void Contact::displayFull() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}