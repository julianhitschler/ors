//this computes the intersections (and the slope at which) of a circle of integer radius r and all integer constant functions parallel to y axes. 
#include <iostream>
#include <math.h> //sqrt
#include <list>
using namespace std;

list<float>* outputyg(int r)
{
	list<float>* xc_yg = new list<float>;
	//list<float>* result = &xc_yg;
	
	for (int i = 1; i < r; ++i) {
		(*xc_yg).push_back (sqrt(r * r - i * i)); // compute y coordinate and append
		(*xc_yg).push_back (- i / sqrt(r * r - i * i)); // compute slope at the intersection
	}
	cout << (*xc_yg).size() << endl;
	//cout << (*result).size() << endl;
	//return xc_yg;
	return xc_yg;
}

int	main()
{	
	int r;
	cout << "Input the integer radius size (larger than 1):" << endl;
	cin >> r;
	list<float>* ygresult = outputyg(r);
	cout << (*ygresult).size() << endl;
	int c = 0;
	for (list<float>::const_iterator iterator = (*ygresult).begin(), end = (*ygresult).end(); iterator != end; ++iterator) 
	{
		if (c%2 == 0) {
			cout << "The y coordinate is " << *iterator << endl;
		} else {
			cout << "The slope is" << *iterator << endl;
		}
		++c;
	}
	return 0;
}
