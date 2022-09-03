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
# define OUTPUT_LIMIT	4

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

#endif
