/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:48:01 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/13 19:23:51 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//Constructors
Contact::Contact() : _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret(""), _index(-1) {}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret, int index)
	: _firstName(firstName), _lastName(lastName), _nickName(nickName), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret), _index(index) {}

// Destructor
Contact::~Contact() {}

void Contact::setIndex(int index) {
    _index = index;
}

int Contact::getIndex() const {
    return _index;
}

std::string Contact::getFirstName() const {
    return _firstName;
}

bool Contact::isValid(std::string firstName) const {
    return (!firstName.empty());
}

void Contact::display() const {
	if (_index == -1)
		std::cout << "Empty contact\n";
	else
	{
		std::cout << "|" << std::setw(10) << std::right << _index
                  << "|" << std::setw(10) << std::right << truncateString(_firstName)
                  << "|" << std::setw(10) << std::right << truncateString(_lastName)
                  << "|" << std::setw(10) << std::right << truncateString(_nickName) << "|"
                  << std::endl;
	}
}

void Contact::full_display() const {
    std::cout << std::endl;
    std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "NickName: " << _nickName << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
    std::cout << std::endl;
}

std::string Contact::truncateString(const std::string& str) const {
    if (str.length() > 10) {
        return str.substr(0, 10 - 1) + ".";
    }
    return str;
}
