#include <cstring>
#include <iostream>
#include <random>
#include <type_traits>

#include <lis/iostream.hpp>

#include "sort/sort.hpp"
#include "test.hpp"


using namespace std;





// functions
/*
 * Воводит график в виде
 * p1.n p1.t
 * ...
 * pN.n pN.t
 */
void print_plot(vector<Point> const &points)
{
	for(auto b = points.begin(), e = points.end(); b != e; ++b)
		printf("%4i %f\n", b->n, b->t);
	return;
}





// main
int main( int argc, char *argv[] )
{
	try
	{
		auto points = test(
			[](int *beg, int *end) { count_sort(beg, end, 0, int(end-beg)+2); },
			1, 2001, 200
		);
		print_plot(points);
	}
	catch(string const &e)
	{
		cerr << "Error: " << e << endl;
	}

	return 0;
}





// end
