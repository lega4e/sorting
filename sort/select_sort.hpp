#ifndef SELECT_SORT_HPP
#define SELECT_SORT_HPP

#include <algorithm>
#include <iterator>





template<typename Iterator>
void select_sort(Iterator b, Iterator e)
{
	Iterator min;
	while(b != e)
	{
		min = b;
		for(auto bb = std::next(b); bb != e; ++bb)
		{
			if(*bb < *min)
				min = bb;
		}
		std::swap(*min, *b);
		++b;
	}
	return;
}





#endif
