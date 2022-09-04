/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:36:36 by mclam             #+#    #+#             */
/*   Updated: 2022/09/02 12:36:36 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define BOLD	"\033[1m"
#define NORMAL	"\033[0m"
#define TAB		"\t"

int main() {
	int			arr1[] = {1, 2, 3, 4, 5};
	char		arr2[] = {'a', 'b', 'c', 'd', 'e'};
	std::string	arr3[] = {"abc", "def", "ghi", "jkl", "mno"};
	Awesome		arr4[5];

	std::cout	<< "Function " BOLD "template<class T>void"
				<< TAB "iter(T, size_t, void (*f)(T const)) \n" NORMAL
				<< "will just accept and print four arrays of different types:"
				<< std::endl;
	iter(arr1, 5, print);
	std::cout << std::endl;
	iter(arr2, 5, print);
	std::cout << std::endl;
	iter(arr3, 5, print);
	std::cout << std::endl;
	iter(arr4, 5, print);
	std::cout << std::endl;
	return 0;
}
