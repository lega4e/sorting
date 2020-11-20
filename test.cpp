#include "test.hpp"

#include <lis/Stopwatch.hpp>


using namespace lis;
using namespace std;





vector<Point> test(
	function<void(int *b, int *e)> algorithm,
	int begn, int endn, int repc
)
{
	vector<Point> points;
	lis::stopwatch_type watch;
	lis::dre_type dre(time(0));

	int *a = new int[endn];
	iota(a, a+endn, 0);
	double time;
	for(int n = begn; n < endn; ++n)
	{
		time = 0.0;
		for(int i = 0; i < repc; ++i)
		{
			shuffle(a, a+n, dre);

			// test
			watch.reset().start();
			algorithm(a, a+n);
			watch.pause();
			time += watch.milliseconds()*1000.0; // microseconds

			if(!check_sort(a, a+n))
			{
				delete[] a;
				throw "sorted fail on "s + to_string(n);
			}
		}

		points.push_back( { n, time / (double)repc } );
	}

	delete[] a;
	return points;
}





// end
