#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <algorithm>





template<typename Iterator>
void quick_sort(Iterator beg, Iterator end)
{
	if(beg == end)
		return;

	Iterator base = std::prev(end);
	Iterator less = beg;
	for(auto b = beg; b != base; ++b)
	{
		if(*b < *base)
			std::swap(*b, *less), ++less;
	}
	std::swap(*less, *base);
	base = less;

	quick_sort(beg, base);
	quick_sort(std::next(base), end);

	return;
}





#endif
