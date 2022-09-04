/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:05:32 by mclam             #+#    #+#             */
/*   Updated: 2022/09/03 17:05:32 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# define MAX_VAL 		750
# define OUTPUT_LIMIT	6
# define SUCCESS		0
# define ERROR			1

template<class Template> class				Array;
template<typename Template> std::ostream	&operator<<(std::ostream &out, const Array<Template> &array);
template<class Array, class T> bool			testFunction(Array &array, T &mirror);
bool										subjectTest( void );

template<class Template> class Array
{
protected:
	Template		*_array;
	unsigned int	_size;
public:
	// Canonical
					Array( void ) : _array( NULL ), _size( 0 ) {}
					Array( const Array<Template> &array) : _array( NULL ), _size( 0 ) { *this = array; }
	virtual			~Array() { delete [] _array; }
	Array<Template>	&operator=( const Array<Template> &array) {
		if (this != &array) {
			if(_size > 0) delete [] _array;
			_size = array._size;
			_array = new Template[_size];
			for (unsigned int i = 0; i < array._size; i++) _array[i] = array._array[i];
		}
		return *this;
	}
	
	// Other member functions
					Array( unsigned int size) : _array( new Template[size] ), _size( size ) {}
	unsigned int	size( void ) const { return _size; }
	Template		&operator[]( const long i ) const {
		if (i < 0 || static_cast<unsigned int>(i) >= _size) throw IndexOutOfBoundsException();
		return _array[i];
	}

	// Index Out Of Bounds Exception
	class IndexOutOfBoundsException  : public std::exception {
	public:
		virtual const char *what() const throw() { return "Index out of bounds"; }
	};
};

template<typename Template> std::ostream	&operator<<(std::ostream &out, const Array<Template> &array) {
	if (array.size() > 0) {
		unsigned int	n = array.size() - 1;
			
		if (n > OUTPUT_LIMIT) {
			for (unsigned int i = 0; i < OUTPUT_LIMIT; i++) out << array[i] << ", ";
			out	<< "..., ";
		}
		else
			for (unsigned int i = 0; i < n; i++) out << array[i] << ", ";
		out	<< array[n];
	}
	return out;
}

template<class Array, class T> bool	testFunction(Array &array, T &mirror)
{
	std::cout	<< "Printing array[" << array.size() << "] = {"
				<< array << "}" << std::endl;

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != array[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return ERROR;
		}
	}

	// Testing exceptions
	std::cout	<< "Trying array[-2]: ";
	try {
		std::cout << array[-2] << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout	<< "Trying array[MAX_VAL]: ";
	try {
		std::cout << array[MAX_VAL] << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return SUCCESS;
}

#endif
