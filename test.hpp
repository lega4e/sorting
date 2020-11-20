#ifndef TEST_HPP
#define TEST_HPP

#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>

#include <lis/rand.hpp>





// types
struct Point
{
	int n;
	double t;
};





/*
 * Проверяет, отсортирована ли
 * последовательность 
 */
template<typename Iterator>
bool check_sort(Iterator b, Iterator e)
{
	if(b == e)
		return true;

	while(std::next(b) != e)
	{
		if(*std::next(b) < *b)
			return false;
		++b;
	}
	return true;
}

/*
 * Делает тесты для алгоритма сортировки и
 * возвращает вектор пар (n; t), где n —
 * размер сортируемого массива, t — коли-
 * чество микросекунд, которые понадобились
 * на один вызов сортировки массива (берётся
 * среднее арифметическое с repeatcount 
 * вызовов)
 */
std::vector<Point> test(
	std::function<void(int *b, int *e)> algorithm,
	int begn, int endn, int repeatcount = 1000
);





#endif
