#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <algorithm>
#include <iterator>
#include <type_traits>
#include <vector>





template<typename Iterator, typename BufIterator>
void _merge_sort(
	Iterator beg, Iterator end,
	BufIterator bufbeg, BufIterator bufend
)
{
	if(beg == end || std::next(beg) == end)
		return;

	auto dis = std::distance(beg, end)/2;
	Iterator m = beg;
	std::advance(m, dis);
	BufIterator bufm = bufbeg;
	std::advance(bufm, dis);

	_merge_sort(bufbeg, bufm, beg, m);
	_merge_sort(bufm, bufend, m, end);

	Iterator it = beg;
	for(
		BufIterator first = bufbeg, second = bufm;
		first != bufm || second != bufend; ++it
	)
	{
		if(first == bufm || (second != bufend && *second < *first))
			*it = std::move(*second), ++second;
		else
			*it = std::move(*first), ++first;
	}

	return;
}

template<typename Iterator>
void merge_sort(Iterator beg, Iterator end)
{
	std::vector<
		typename std::remove_reference<decltype(*beg)>::type
	> buf(std::distance(beg, end));
	std::copy(beg, end, buf.begin());
	_merge_sort(beg, end, buf.begin(), buf.end());
	return;
}





#endif
