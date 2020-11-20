#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <iterator>
#include <type_traits>





inline int heap_parent(int i)
{
	return i == 0 ? -1 : (i - 1) / 2;
}

inline int heap_child(int i, int ch)
{
	return i * 2 + (ch == 0 ? 1 : 2);
}


template<typename Iterator>
void heap_raise(Iterator beg, Iterator end, int i)
{
	if( int par = heap_parent(i); par >= 0 && *(beg + i) < *(beg + par) )
	{
		std::swap(*(beg + i), *(beg + par));
		return heap_raise(beg, end, par);
	}
	return;
}


template<typename Iterator>
void heap_down(Iterator beg, Iterator end, int i)
{
	int ch = heap_child(i, 0);
	if(ch >= end - beg)
		return;

	if(ch+1 < end - beg && *(beg + ch + 1) < *(beg + ch))
		++ch;

	if( *(beg + ch) < *(beg + i) )
	{
		std::swap( *(beg + ch), *(beg + i) );
		return heap_down(beg, end, ch);
	}

	return;
}

template<typename T>
void heap_push(std::vector<T> &heap, T const &value)
{
	heap.push_back(value);
	return heap_raise( heap.begin(), heap.end(), heap.size()-1 );
}

template<typename T>
void heap_erase(std::vector<T> &heap, int i)
{
	heap[i] = heap.back();
	heap.pop_back();
	return heap_down( heap.begin(), heap.end(), i );
}

template<typename Iterator>
void heap_sort(Iterator beg, Iterator end)
{
	typedef typename std::remove_reference<decltype(*beg)>::type value_type;
	std::vector<value_type> heap;

	if( std::is_same<
		typename std::iterator_traits<decltype(beg)>::iterator_category,
		std::random_access_iterator_tag
	>::value )
	{
		heap.reserve( std::distance(beg, end) );
	}

	for(auto b = beg; b != end; ++b)
		heap_push(heap, *b);

	for(; beg != end; ++beg)
	{
		*beg = heap.front();
		heap_erase(heap, 0);
	}

	return;
}


/*
 * template<
 *     typename Iterator,
 *     typename Comparator = std::less<decltype(*Iterator())>
 * >
 * void heap_raise(
 *     Iterator beg, Iterator end,
 *     int i, Comparator cmp = Comparator()
 * )
 * {
 *     if( int par = heap_parent(i); par >= 0 && cmp(*(beg + i), *(beg + par)) )
 *     {
 *         std::swap(*(beg + i), *(beg + par));
 *         return heap_raise(beg, end, par, cmp);
 *     }
 *     return;
 * }
 * 
 * template<
 *     typename Iterator,
 *     typename Comparator = std::less<decltype(*Iterator())>
 * >
 * void heap_down(
 *     Iterator beg, Iterator end,
 *     int i, Comparator cmp = Comparator()
 * )
 * {
 *     int ch = heap_child(i, 0);
 *     if(ch >= end - beg)
 *         return;
 * 
 *     if( ch+1 < end - beg && cmp(*(beg + ch + 1), *(beg + ch)) )
 *         ++ch;
 * 
 *     if( *(beg + ch) < *(beg + i) )
 *     {
 *         std::swap( *(beg + ch), *(beg + i) );
 *         return heap_down(beg, end, ch, cmp);
 *     }
 * 
 *     return;
 * }
 * 
 * 
 * 
 * template<
 *     typename T,
 *     typename Comparator = std::less<const T &>
 * >
 * void heap_push(
 *     std::vector<T> &heap,
 *     T const &value,
 *     Comparator cmp = Comparator()
 * )
 * {
 *     heap.push_back(value);
 *     return heap_raise(
 *         heap.begin(), heap.end(),
 *         heap.size()-1, cmp 
 *     );
 * }
 * 
 * template<
 *     typename T,
 *     typename Comparator = std::less<const T &>
 * >
 * void heap_erase(
 *     std::vector<T> &heap, int i,
 *     Comparator cmp = Comparator()
 * )
 * {
 *     heap[i] = heap.back();
 *     heap.pop_back();
 *     return heap_down( heap.begin(), heap.end(), i, cmp );
 * }
 * 
 * 
 * 
 * template<
 *     typename Iterator,
 *     typename Comparator = std::less<decltype(*Iterator())>
 * >
 * void heap_sort(
 *     Iterator beg, Iterator end,
 *     Comparator cmp = Comparator()
 * )
 * {
 *     typedef typename std::remove_reference<decltype(*beg)>::type value_type;
 *     std::vector<value_type> heap;
 * 
 *     if( std::is_same<
 *         typename std::iterator_traits<decltype(beg)>::iterator_category,
 *         std::random_access_iterator_tag
 *     >::value )
 *     {
 *         heap.reserve( std::distance(beg, end) );
 *     }
 * 
 *     for(auto b = beg; b != end; ++b)
 *         heap_push(heap, *b, cmp);
 * 
 *     for(; beg != end; ++beg)
 *     {
 *         *beg = heap.front();
 *         heap_erase(heap, 0, cmp);
 *     }
 * 
 *     return;
 * }
 */





#endif
