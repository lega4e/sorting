#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include <iterator>






template<typename Iterator>
void bubble_sort(Iterator b, Iterator e)
{
	while(std::prev(e) != b)
	{
		for(Iterator bb = b; std::next(bb) != e; ++bb)
		{
			if(*std::next(bb) < *bb)
				std::swap(*std::next(bb), *bb);
		}
		
		--e;
	}
	return;
}





#endif
