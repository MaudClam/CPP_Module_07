/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:05:53 by mclam             #+#    #+#             */
/*   Updated: 2022/09/03 17:05:53 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main(int, char**) {
	srand((unsigned int)time(NULL));
	
	{
		std::cout << "\n===Subject Test==================" << std::endl;
		bool res = subjectTest();
		std::cout << "===" << (res == SUCCESS ? "SUCCESS\n" : "ERROR\n");
	}

	{
		std::cout << "\n===Bool Test=====================" << std::endl;
		Array<int>	array(MAX_VAL);
		int			*mirror = new int[MAX_VAL];
		for (int i = 0; i < MAX_VAL; i++) {
			const bool value = static_cast<bool>(std::rand() % 2);
			array[i] = value;
			mirror[i] = value;
		}
		bool		res = testFunction(array, mirror);
		std::cout << "===" << (res == SUCCESS ? "SUCCESS\n" : "ERROR\n");
		delete [] mirror;
	}

	{
		std::cout << "\n===Double Test===================" << std::endl;
		Array<double>	array(MAX_VAL);
		double			*mirror = new double[MAX_VAL];
		for (int i = 0; i < MAX_VAL; i++) {
			const double value = static_cast<double>(std::rand());
			array[i] = value;
			mirror[i] = value;
		}
		bool		res = testFunction(array, mirror);
		std::cout << "===" << (res == SUCCESS ? "SUCCESS\n" : "ERROR\n");
		delete [] mirror;
	}

	{
		std::cout << "\n===Char Test=====================" << std::endl;
		Array<char>	array(MAX_VAL);
		char		*mirror = new char[MAX_VAL];
		for (int i = 0; i < MAX_VAL; i++) {
			const char value = static_cast<char>(std::rand() % 93 + 33);
			array[i] = value;
			mirror[i] = value;
		}
		bool		res = testFunction(array, mirror);
		std::cout << "===" << (res == SUCCESS ? "SUCCESS\n" : "ERROR\n");
		delete [] mirror;
	}

	{
		std::cout << "\n===Std::srting Test==============" << std::endl;
		Array<std::string>	array(MAX_VAL);
		std::string			*mirror = new std::string[MAX_VAL];
		for (int i = 0; i < MAX_VAL; i++) {
			int		ln = std::rand() % 9 + 3;
			char	value[ln];
			for (int j = 0; j < ln; j++) {
				value[j] = static_cast<char>(std::rand() % 25 + 97);
			}
			value[ln] = 0;
			array[i] = std::string(value);
			mirror[i] = std::string(value);
		}
		bool	res = testFunction(array, mirror);
		std::cout << "===" << (res == SUCCESS ? "SUCCESS\n" : "ERROR\n");
		delete [] mirror;
	}

	return 0;
}

bool	subjectTest( void ) {
	Array<int>	numbers(MAX_VAL);
	int			*mirror = new int[MAX_VAL];
	
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout	<< "Printing numbers[" << numbers.size() << "] = {"
				<< numbers << "}" << std::endl;
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return ERROR;
		}
	}
	
	std::cout	<< "Trying 'numbers[-2] = 0': ";
	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout	<< "Trying 'numbers[MAX_VAL] = 0': ";
	try {
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	std::cout	<< "Rewritten and\nprinting numbers[" << numbers.size()
				<< "] = {" << numbers << "}" << std::endl;
	
	delete [] mirror;
	return SUCCESS;
}
