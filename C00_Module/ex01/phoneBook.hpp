/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:45:56 by daduarte          #+#    #+#             */
/*   Updated: 2025/01/20 15:43:17 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "phoneBook.hpp"
#include "contact.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void displayContacts() const;
		void search() const;
		bool isFull() const;
		bool addContact();
		void updateContacts();
	private:
		static const int	maxContacts = 8;
		Contact _contacts[maxContacts];
		int	_contactCount;
};

#endif
