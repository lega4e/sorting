#ifndef SHAKER_SORT_HPP
#define SHAKER_SORT_HPP





template<typename Iterator>
void shaker_sort(Iterator b, Iterator e)
{
	while(b != e)
	{
		for(auto bb = b; std::next(bb) != e; ++bb)
		{
			if(*bb > *std::next(bb))
				std::swap(*bb, *std::next(bb));
		}
		--e;

		if(b == e)
			break;

		for(auto ee = std::prev(e); ee != b; --ee)
		{
			if(*std::prev(ee) > *ee)
				std::swap(*std::prev(ee), *ee);
		}
		++b;
	}
	return;
}





#endif
