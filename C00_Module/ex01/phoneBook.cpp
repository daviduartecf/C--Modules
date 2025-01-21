/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:46:04 by daduarte          #+#    #+#             */
/*   Updated: 2025/01/21 12:30:30 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"
#include "contact.hpp"

PhoneBook::PhoneBook(): _contactCount(0) {}

PhoneBook::~PhoneBook() {}

std::string	getUserInput(std::string msg)
{
	std::string user_input;

	std::cout << msg;
	while (user_input.empty())
	{
		std::getline(std::cin, user_input);
		if (std::cin.eof())
		{
			std::cout << std::endl << RED << "Ending program..." << std::endl;
			return "";
		}
		else if (user_input.empty())
			std::cout << std::endl << "Input can't be empty. Please try again: ";
		else
			break;
	}
	return (user_input);
}

void PhoneBook::displayContacts() const
{
	if (_contactCount == 0)
	{
		std::cout << std::endl << "Empty phonebook!\n" << std::endl;
		return ;
	}
	std::cout << YELLOW << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|"
              << std::endl;

    std::cout << std::string(45, '-') << std::endl;
	for(int i = 0; i < maxContacts; i++)
	{
		if (_contacts[i].isValid(_contacts[i].getFirstName()))
		{
			_contacts[i].display();
			std::cout << std::string(45, '-') << std::endl;
		}
	}
}

bool PhoneBook::isFull() const
{
	if (_contactCount == maxContacts)
	{
		return true;
	}
	else
		return false;
}

void PhoneBook::updateContacts()
{
	for(int i = maxContacts - 1; i > 0; i--)
	{
		_contacts[i] = _contacts[i - 1];
		_contacts[i].setIndex(_contacts[i - 1].getIndex() + 1);
	}
}

bool PhoneBook::addContact()
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	first_name = getUserInput("Enter first name: ");
	if (first_name.empty())
		return false;
	last_name = getUserInput("Enter last name: ");
	if (last_name.empty())
		return false;
	nick_name = getUserInput("Enter nickname: ");
	if	(nick_name.empty())
		return false;
	phone_number = getUserInput("Enter phone number: ");
	if	(phone_number.empty())
		return false;
	darkest_secret = getUserInput("Enter darkest secret: ");
	if	(darkest_secret.empty())
		return false;
	this->_contacts[0] = Contact(first_name, last_name, nick_name, phone_number, darkest_secret, 1);
	std::cout << std::endl << GREEN << "Contact " << first_name << " added!" << RESET << std::endl;
	_contactCount++;
	return true;
}

void PhoneBook::search() const
{
	int index;

	if (this->_contactCount == 0)
		return;
	std::cout << BLUE << "Enter the index:" << RESET << std::endl;
	std::cin >> index;
	if (std::cin.fail()) {
		std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << std::endl << RED << "INVALID INPUT: Please enter a valid number." << RESET << std::endl;
		return;
	}
	if (index <= 0 || index > maxContacts) {
        std::cout << std::endl << RED << "INVALID INDEX: Index out of range." << RESET << std::endl;
		std::cin.ignore(100000, '\n');
        return;
    }
	for (int i = 0; i < maxContacts; i++) {
        if (_contacts[i].getIndex() == index) {
            _contacts[i].full_display();
			std::cin.ignore(100000, '\n');
            return;
        }
    }
	std::cout << std::endl << RED << "No contact found with the given index." << RESET << std::endl;
	std::cin.ignore(100000, '\n');
}
