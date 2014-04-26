//#include <algorithm>
using namespace std;

template <typename T>
class BinHeap
{
    public:
        BinHeap();
        BinHeap(T *arr, int length);

        //~BinHeap();
        //BinHeap(const BinHeap& other);

        void insert(T x);
        T getMin();
        void dumpHeap(string s);
        int size();

    private:
        void expandArray();
        void swap(int x, int y);
        void percUp(int n);
        void percDown(int n);
        //del();

        T *a;
        int lastindex, asize;
};

template <typename T>
BinHeap<T>::BinHeap()
{
    a = new T [1];
    lastindex = 0;
    asize = 1;
}

template <typename T>
BinHeap<T>::BinHeap(T *arr, int length)
{
    a = new T [length+1];
    lastindex = 0;
    asize = length+1;

    for (int i = 0; i < length; ++i)
        insert(arr[i]);
}

template <typename T>
void BinHeap<T>::insert(T x)
{
    lastindex++;
    if (lastindex == asize)
        expandArray();
    //cout << "array expanded" << endl;
    a[lastindex] = x;
    //cout << "element inserted" << endl;
    percUp(lastindex);
}

template <typename T>
T BinHeap<T>::getMin()
{
    T tmp = a[1];
    a[1] = a[lastindex];
    --lastindex;
    percDown(1);
    //delete
    return tmp;
}


template <typename T>
void BinHeap<T>::dumpHeap(string s)
{
    cout << s << endl;
	for (int i = 1; i <= lastindex; i++)
		cout << a[i].toString() << endl; // .toString()
}

template <typename T>
int BinHeap<T>::size()
{
    return lastindex;
}



template <typename T>
void BinHeap<T>::expandArray()
{
    asize *= 2;
    T *temp = new T[asize];
    //cout << "new array created" << endl;
    for(int i = 1; i < lastindex; ++i) {
        //cout << "copying element";
        temp[i] = a[i];
        //cout << " DONE!" << endl;
    }
    //cout << "old array copied" << endl;
    delete[] a;
    //cout << "old array deleted" << endl;
    a = temp;
}

template <typename T>
void BinHeap<T>::swap(int x, int y)
{
    T tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
}

template <typename T>       //make me recursive
void BinHeap<T>::percUp(int n)
{
    if (n == 1)
        return;
    else {
        if (a[n] < a[n/2]) {// need operator overload for < instead of a[n].getSecond()
            swap(n, n/2);
            percUp(n/2);
        }
        else return;
    }
}

template <typename T>
void BinHeap<T>::percDown(int n)
{
    if (n*2 > lastindex)
        return;

    else if ((n*2)+1 > lastindex) {
        if (a[n*2] < a[n]) // need operator overload for <
            swap(n, n*2);
        return;
    }

    else {
        int smallest;
        if (a[n*2] < a[(n*2)+1]) // need operator overload for <
            smallest = n*2;
        else
            smallest = (n*2)+1;
        if (a[smallest] < a[n]) { // need operator overload for <
            swap(n, smallest);
            percDown(smallest);
        }
    }
    return;
}
