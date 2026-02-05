/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:00:36 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/04 17:43:15 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook
{
	private:
		Contact contacts[8];
		int		nextIndex;
		int		count;
	public:
		PhoneBook();
		~PhoneBook();
		void addContact(const Contact& c);
		void displayContacts() const;
		void displayContactByIndex(int index) const;

		int	getCount() const;
};

#endif