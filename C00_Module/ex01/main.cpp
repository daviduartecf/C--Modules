/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:18:02 by daduarte          #+#    #+#             */
/*   Updated: 2025/01/21 13:09:00 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phoneBook.hpp"
#include <iostream>
#include <string>
#include <csignal>
#include <cstdlib>

void handleSigint(int signum)
{
	std::cout << "Exiting with " << signum << std::endl;
	exit(0);
}

void	display_menu(void)
{
	std::cout << YELLOW;
	std::cout << "        ┌─┐┬ ┬┌─┐┌┐┌┌─┐┌┐ ┌─┐┌─┐┬┌─" << std::endl;
	std::cout << "        ├─┘├─┤│ ││││├┤ ├┴┐│ ││ │├┴┐" << std::endl;
	std::cout << "        ┴  ┴ ┴└─┘┘└┘└─┘└─┘└─┘└─┘┴ ┴" << std::endl;
	std::cout << "+-----------------------------------------+" << std::endl;
	std::cout << "|                  1-ADD                  |" << std::endl;
	std::cout << "|                 2-SEARCH                |" << std::endl;
	std::cout << "|                  3-EXIT                 |" << std::endl;
	std::cout << "+-----------------------------------------+" << std::endl;
	std::cout << "Enter an option:" << std::endl;
	std::cout << RESET;
}

int	main(void)
{
	signal(SIGINT, handleSigint);
	PhoneBook phoneBook;
	std::string option;

	while (true)
	{
		if (std::cin.eof())
		{
			std::cout << "Exiting..." << std::endl;
			break;
		}
		display_menu();
		if (!std::getline(std::cin, option)) {
			if (std::cin.eof()) {
				std::cout << "Exiting..." << std::endl;
				break;
			}
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid input." << std::endl;
			continue;
		}
		if (option.compare("ADD") == 0)
		{
			phoneBook.updateContacts();
			if (phoneBook.addContact() == false)
				return (1);
		}
		else if (option.compare("SEARCH") == 0)
		{
			phoneBook.displayContacts();
			phoneBook.search();
		}
		else if (option.compare("EXIT") == 0) {
			std::cout << std::endl << RED << "Exiting..." << std::endl;
			break;
		}
		else
			std::cout << "Invalid input. Enter one of the following options:" << RESET << std::endl;
	}
	return (0);
}

