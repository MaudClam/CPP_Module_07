/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:35:25 by mclam             #+#    #+#             */
/*   Updated: 2022/09/02 12:35:25 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <class T> void	iter(T *arr, size_t len, void (*f)(T const &element)) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template<class T> void	print(T const &element) {
	std::cout << element << " ";
}

// TEST COMPLEX CLASS FROM CHECKLIST EX01
class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream &o, Awesome const &rhs ) { o << rhs.get(); return o; }

#endif
