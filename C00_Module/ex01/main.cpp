/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:18:02 by daduarte          #+#    #+#             */
/*   Updated: 2025/01/20 15:49:04 by daduarte         ###   ########.fr       */
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

void wait_for_enter()
{
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore(1000, '\n');
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
		if (!(std::cin >> option)) {
			if (std::cin.eof()) {
				std::cout << "Exiting..." << std::endl;
				break;
			}
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid input." << std::endl;
			continue;
		}
		std::cin.ignore();
		if (option == "ADD")
		{
			phoneBook.updateContacts();
			if (phoneBook.addContact() == false)
				return (1);
		}
		else if (option == "SEARCH")
		{
			phoneBook.displayContacts();
			phoneBook.search();
		}
		else if (option == "EXIT") {
			std::cout << std::endl << RED << "Exiting..." << std::endl;
			break;
		}
		else
			std::cout << "Invalid input. Enter one of te following options:" << RESET << std::endl;
		wait_for_enter();
	}
	return (0);
}

