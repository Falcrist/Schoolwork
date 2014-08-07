// Pair.h
// template for a pair of items of arbitrary types

#include <sstream>
using namespace std;

template <typename S, typename T>
class Pair
{
	public:
		Pair();
        Pair(S,T);

        Pair(Pair&);
        ~Pair();
        int getPairCount();
        const Pair &operator=(const Pair&);
        bool operator<(const Pair&) const;

        string toString();

        S* getFirst();
        T* getSecond();

        void setFirst(S);
        void setSecond(T);

	private:
		S *f;
		T *s;
		static int pairCount;

};

// 0-parameter constructor
template <typename S, typename T>
Pair<S,T>::Pair()
{
	f = NULL;
	s = NULL;
	++pairCount;
}

// 2-param constructor
template <typename S, typename T>
Pair<S,T>::Pair(S x, T y)
{
	f = new S;  *f = x;
	s = new T;  *s = y;
	++pairCount;
}

template <typename S, typename T>
Pair<S,T>::Pair(Pair &other)
{
	f = NULL;
	s = NULL;
	if (other.f != NULL)
		f = new S(*other.f);
	if (other.s != NULL)
		s = new T(*other.s);
	++pairCount;
}

template <typename S, typename T>
Pair<S,T>::~Pair()
{
	if (f != NULL)
		delete f;
	if (s != NULL)
		delete s;
	f = NULL;
	s = NULL;
	--pairCount;
}

template <typename S, typename T>
int Pair<S,T>::pairCount=0;

template <typename S, typename T>
int Pair<S,T>::getPairCount()
{
	return pairCount;
}

template <typename S, typename T>
const Pair<S,T>&Pair<S,T>::operator=(const Pair<S,T> &other)
{
	if (this != &other) {
		if (f != NULL)
			delete f;
		if (s != NULL)
			delete s;
		f = NULL;
		s = NULL;
		if (other.f != NULL)
			f = new S(*other.f);
		if (other.s != NULL)
			s = new T(*other.s);
	}
	return *this;
}

template <typename S, typename T>
bool Pair<S,T>::operator<(const Pair<S,T> &one) const
{
	if ((s != NULL) && (one.s != NULL)) {
		T x, y;
		x = *s;
		y = *one.s;
		return (x < y);
	}
	else
		return false;
}

// get first element in pointer
template <typename S, typename T>
S* Pair<S,T>::getFirst()
{
	if (f!=NULL) {
		S *tmp = new S;
		*tmp = *f;
		return tmp;
	}
	else
		return NULL;
}

// get second element in pointer
template <typename S, typename T>
T* Pair<S,T>::getSecond()
{
	if (s!=NULL) {
		T *tmp = new T;
		*tmp = *s;
		return tmp;
		}
	else
		return NULL;
}

// set first element
template <typename S, typename T>
void Pair<S,T>::setFirst(S x)
{
	if (f==NULL)
		f = new S;
	*f = x;
}

// set second element
template <typename S, typename T>
void Pair<S,T>::setSecond(T y)
{
	if (s==NULL)
		s = new T;
	*s = y;
}

// make a string representation
template <typename S, typename T>
string Pair<S,T>::toString()
{
	stringstream ss;
	if (f==NULL)
		ss<<"NULL";
	else
		ss<<(*f);
	if (s==NULL)
		ss<<"NULL";
	else
		ss<<(*s);
	return ss.str();
}
