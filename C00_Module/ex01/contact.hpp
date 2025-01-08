/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:46:14 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/13 19:21:01 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	public:
		//Constructor
		Contact();
		Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret, int index);

		//Destructor
		~Contact();

		bool isValid(std::string firstName) const;
		void display() const;
		void full_display() const;
		void setIndex(int index);
		int getIndex() const;
		std::string getFirstName() const;
		std::string truncateString(const std::string& str) const;
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
		int	_index;
};

#endif
