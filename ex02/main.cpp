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

#define MAX_VAL 5

int main(int, char**) {
	Array<int>	numbers(MAX_VAL);
	int			*mirror = new int[MAX_VAL];
	
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int	value = std::rand();
		
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout	<< "numbers[" << numbers.size() << "] = {"
				<< numbers << "}" << std::endl;

	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	std::cout	<< "numbers[" << numbers.size() << "] = {"
				<< numbers << "}" << std::endl;
	delete [] mirror;//
	return 0;
}
