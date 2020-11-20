#ifndef COUNT_SORT_HPP
#define COUNT_SORT_HPP

#include <cstring>





template<typename Iterator, typename T>
void count_sort(Iterator beg, Iterator end, T min, T max)
{
	int n = max - min + 1;
	T *vals = new T[n];
	memset(vals, 0, sizeof(T) * n);

	for(auto b = beg; b != end; ++b)
		++vals[*beg - min];

	Iterator b = beg;
	for(int valit = 0; valit < n; ++valit)
	{
		while(vals[valit])
		{
			*b = valit;
			++b;
			--vals[valit];
		}
	}

	delete[] vals;
	return;
}





#endif
