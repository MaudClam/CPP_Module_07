/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:34:05 by mclam             #+#    #+#             */
/*   Updated: 2022/08/24 15:34:05 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

int main( void ) {
	{
		int a = 2;
		int b = 3;

		std::cout	<< "\na = " << a << " " << &a << ", "
					<< "b = " << b << " " << &b << std::endl;
		std::cout << "::swap( a, b );" << std::endl;
		::swap( a, b );
		std::cout	<< "a = " << a << " " << &a << ", "
					<< "b = " << b << " " << &b << std::endl;

		std::cout	<< "\nmin( a, b ) = " << ::min( a, b )
					<< " " << &::min( a, b ) << std::endl;
		std::cout 	<< "max( a, b ) = " << ::max( a, b )
					<< " " << &::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		std::cout	<< "\nc = " << c << " " << &c << ", "
					<< "d = " << d << " " << &d << std::endl;
		std::cout << "::swap( c, d );" << std::endl;
		::swap(c, d);
		std::cout	<< "c = " << c << " " << &c << ", "
					<< "d = " << d << " " << &d << std::endl;
		
		std::cout	<< "\nmin( c, d ) = " << ::min( c, d )
					<< " " << &::min( c, d ) << std::endl;
		std::cout 	<< "max( c, d ) = " << ::max( c, d )
					<< " " << &::max( c, d ) << std::endl;

		a = 8;
		b = 8;
		
		std::cout	<< "\na = " << a << " " << &a << ", "
					<< "b = " << b << " " << &b << std::endl;
		std::cout	<< "min( a, b ) = " << ::min( a, b )
					<< " " << &::min( a, b ) << std::endl;
		std::cout 	<< "max( a, b ) = " << ::max( a, b )
					<< " " << &::max( a, b ) << std::endl;
	}

	{
		std::cout << "\n===Test with complex class Awesome===" << std::endl;
		Awesome a(2), b(4);

		std::cout	<< "\na = " << a << " " << &a << ", "
					<< "b = " << b << " " << &b << std::endl;
		std::cout << "::swap( a, b );" << std::endl;
		::swap( a, b );
		std::cout	<< "a = " << a << " " << &a << ", "
					<< "b = " << b << " " << &b << std::endl;
		
		std::cout	<< "\nmin( a, b ) = " << ::min( a, b )
					<< " " << &::min( a, b ) << std::endl;
		std::cout 	<< "max( a, b ) = " << ::max( a, b )
					<< " " << &::max( a, b ) << std::endl;
	}

	return 0;
}
