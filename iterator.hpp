/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:01:08 by tliangso          #+#    #+#             */
/*   Updated: 2022/12/21 22:23:06 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <iostream>

namespace ft
{
	// empty class to identify categroy of an iterator as an input iterator
	struct input_iterator_tag {};
	// empty class to identify categroy of an iterator as an output iterator
	struct output_iterator_tag {};
	// empty class to identify categroy of an iterator as an forward iterator
	struct forward_iterator_tag : public input_iterator_tag {};
	// empty class to identify category of an iterator as an random-access iterator
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// std::iterator is the base class provided to simplify definitions of the required types for iterators.

	// _Category the category of the iterator. Must be one of the iterator category tags.
	// _T the type of the values that can be obtained by deferencing the iterator. This type should be void for output iterators.
	// _Distance a type that can be used to identify distance between iterators
	// _Pointer defines a pointer to the type iterated over (_T)
	// _Reference defines a reference to the type iterated over (_T)
	template < class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference &T >
	struct iterator
	{
		// category of the iterator
		typedef Category iterator_category;
		// type of the values that can be obtained by deferenceing the iterator
		typedef T value_type;
		// type that can be used to identify distance between iterators
		typedef Distance difference_type;
		// pointer to the type iterated over
		typedef Pointer pointer;
		// reference to the type iterated over
		typedef Reference reference;
	};

	// Traits class defining properties of iterators.
	// Standard algorithms determine certain properties of the iterators passed to
	// them and the range they represent by using the members of the corresponding
	// iterator_traits instantiation.
	template < class Iterator >
	struct iterator_traits
	{
		// catergory of the iterator
		typedef typename Iterator::iterator_category iterator_category;
		// type of the values that can be obtained by deferencing the iterator
		typedef typename Iterator::value_type value_type;
		// type that can be used to identify distance between iterators
		typedef typename Iterator::difference_type difference_type;
		// pointer to the type iterated over (value_type)
		typedef typename Iterator::pointer pointer;
		// reference to the type iterated over (value_type)
		typedef typename Iterator::reference reference;
	};

	template < class T >
	struct iterator_traits< T* >
	{
		// category of the iterator
		typedef random_access_iterator_tag iterator_category;
		// type of the values that can be obtained by deferencing the iterator
		typedef T value_type;
		// type that can be used to idetify distane between iterators
		typedef ptrdiff_t difference_type;
		// pointer to the type iterated over (value_type)
		typedef T* pointer;
		// pointer to the type iterated over (value_type)
		typedef T& reference;
	};

	// Traits class defining properties of iterators.
	// Standard algorithms determine certain properties of the iterators passed to
	// them and the range they represent by using members of the corresponding iterator_traits instaniation.
	// T ft:iterator
	template < class T >
	struct iterator_traits< T* const >
	{
		// category of the iterator
		typedef random_access_iterator_tag iterator_category;
		// type of the values that can be obtained by deferencing the iterator
		typedef T value_type;
		// type that can be used to idetify distane between iterators
		typedef ptrdiff_t difference_type;
		// pointer to the type iterated over (value_type)
		typedef T* pointer;
		// pointer to the type iterated over (value_type)
		typedef T& reference;
	};

	// This class reverse the direction in which a bidirectional or
	// random-access iterator iterates through a range.
	// Iterator Iterator Class
	template < class Iterator >
	class reverse_iterator
	{
		public:
			// Iterator's type
			typedef Iterator iterator_type;
			// Preverse Iterator's cateogry
			typedef typename iterator_traits< Iterator >::iterator_category iterator_catrgory;
			// Preserves Iterator's value type
			typedef typename iterator_traits< Iterator >::value_type value_type;
			// Preserves Iterator's difference type
			typedef typename iterator_traits< Iterator >::difference_type difference_type;
			// Preserves Iterator's pointer type
			typedef typename iterator_traits< Iterator >::pointer pointer;
			// Preserves Iterator's reference type
			typedef typename iterator_traits< Iterator >::reference reference;

		protected:
			iterator_type current;

		public:
			// default constructor
			// Constructs a reverse iteratore that points to no object.
			// The interal base iterator is value-initialized.
			reverse_iterator() : current(){};

			// initialization constructor
			// Constructs a reverse iterator from some original iterator it. The behavior
			// of the constructed object replicates the original, except that it iterates
			// through its pointed elements in the reverse order.

			// it An iterator, whose sense of iteration is inverted in the
			// constructed object. Member type iterator_type is the underlying
			// bidirectional iterator type (tyhe class template parameter: Iterator).
			explicit reverse_iterator(iterator_type it) : current(it){};

			// copy / type-cast constructor
			// Constructs a reverse iterator from some other reverse iterator. The
			// Constructed object keeps the same sense of iteration as rev_it.

			// rev_it An iterator of a reverse_iterator type, whose sense of
			// iteration is preserved.
			template < class Iter >
			reverse_iterator(const reverse_iterator< Iter >& rev_it) : current(rev_it.base()){};

			// destructor
			virtual ~reverse_iterator() {};

			// 

	}

} // namespace ft


#endif
