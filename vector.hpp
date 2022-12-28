/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:32:09 by tliangso          #+#    #+#             */
/*   Updated: 2022/12/21 22:01:08 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>

# include "iterator.hpp"

namespace ft
{
	template < class _T, class _Alloc = std::allocator< _T > >
	class vector
	{
		public:
			// value_type to template (_T)
			typedef _T value_type;
			// value_type to template const (_T)
			typedef _T const const_value_type;
			// allocator_type to template (_Alloc)
			typedef _Alloc allocator_type;
			// reference default to value_type&
			typedef typename allocator_type::reference reference;
			// const_reference to const value_type&
			typedef typename allocator_type::const_reference const_reference;
			// pointer to value_type*
			typedef typename allocator_type::pointer pointer;
			// const pointer to const value_type*
			typedef typename allocator_type::const_pointer const_pointer;
			// random access iterator
			typedef typename ft::random_access_iterator< value_type > iterator;


	}
} // namespace ft

#endif
