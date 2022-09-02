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

#endif
