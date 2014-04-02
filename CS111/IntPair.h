#include <sstream>
#include <iostream>
using namespace std;

class IntPair
{
	public:
		IntPair();
		IntPair(int, int);
		string toString();
		void setFirst(int);
		void setSecond(int);
		int getFirst();
		int getSecond();
		
	private:
		int first, second;
};

IntPair::IntPair()
{
	first = second = 0;
}

IntPair::IntPair(int a, int b)
{
	first = a;
	second = b;
}

string IntPair::toString()
{
	stringstream ss;
	ss << first << ", " << second << "\n";
	return ss.str();
}

void IntPair::setFirst(int a)
{
	first = a;
}

void IntPair::setSecond(int b)
{
	second = b;
}

int IntPair::getFirst()
{
	return first;
}

int IntPair::getSecond()
{
	return second;
}
