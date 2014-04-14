#include <sstream>
#include <iostream>
#include "Pair.h"
using namespace std;

template <typename MyType>
class Minmaxpair : public Pair<MyType>
{
	public:
		Minmaxpair();
		Minmaxpair(MyType, MyType);
		MyType getMin();
		MyType getMax();
};

template <typename MyType>
Minmaxpair<MyType>::Minmaxpair() : Pair<MyType>()
{

}

template <typename MyType>
Minmaxpair<MyType>::Minmaxpair(MyType a, MyType b) : Pair<MyType>(a, b)
{

}

template <typename MyType>
MyType Minmaxpair<MyType>::getMax()
{
	if (Pair<MyType>::getFirst() > Pair<MyType>::getSecond())
		return Pair<MyType>::getFirst();
	else
		return Pair<MyType>::getSecond();
}

template <typename MyType>
MyType Minmaxpair<MyType>::getMin()
{
	if (Pair<MyType>::getFirst() < Pair<MyType>::getSecond())
		return Pair<MyType>::getFirst();
	else
		return Pair<MyType>::getSecond();
}
