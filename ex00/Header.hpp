/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:36:08 by mclam             #+#    #+#             */
/*   Updated: 2022/09/02 12:36:08 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

# include <iostream>

template<class T> void	swap(T &a, T &b) {
	T	c;
	
	c = a;
	a = b;
	b = c;
}

template<class T> T		&min(T &a, T &b) {
	return a < b ? a : b;
}

template<class T> T		&max(T &a, T &b) {
	return a > b ? a : b;
}

// TEST COMPLEX CLASS FROM CHECKLIST EX00
class TestComplexClass
{
public:
	TestComplexClass( void ) : _n( 0 ) {}
	TestComplexClass( int n ): _n( n ) {}
	TestComplexClass &operator=( TestComplexClass &a ) { _n = a._n; return *this; }
	bool operator==( TestComplexClass const &rhs ) const { return (this->_n == rhs._n); }
	bool operator!=( TestComplexClass const &rhs ) const{ return (this->_n != rhs._n); }
	bool operator>( TestComplexClass const &rhs ) const { return (this->_n > rhs._n); }
	bool operator<( TestComplexClass const &rhs ) const { return (this->_n < rhs._n); }
	bool operator>=( TestComplexClass const &rhs ) const { return (this->_n >= rhs._n); }
	bool operator<=( TestComplexClass const &rhs ) const { return (this->_n <= rhs._n); }
	int get_n() const { return _n; }
private:
	int _n;
};

std::ostream &operator<<(std::ostream &o, const TestComplexClass &a) { o << a.get_n(); return o; }


#endif
