#include <sstream>
#include <iostream>
using namespace std;

template <typename MyType>
class Pair
{
	public:
		Pair();
		Pair(MyType, MyType);
		string toString();
		void setFirst(MyType);
		void setSecond(MyType);
		MyType getFirst();
		MyType getSecond();
		
	private:
		MyType first, second;
};

template <typename MyType>
Pair<MyType>::Pair()
{
	
}

template <typename MyType>
Pair<MyType>::Pair(MyType a, MyType b)
{
	first = a;
	second = b;
}

template <typename MyType>
string Pair<MyType>::toString()
{
	stringstream ss;
	ss << first << ", " << second << "\n";
	return ss.str();
}

template <typename MyType>
void Pair<MyType>::setFirst(MyType a)
{
	first = a;
}

template <typename MyType>
void Pair<MyType>::setSecond(MyType b)
{
	second = b;
}

template <typename MyType>
MyType Pair<MyType>::getFirst()
{
	return first;
}

template <typename MyType>
MyType Pair<MyType>::getSecond()
{
	return second;
}
