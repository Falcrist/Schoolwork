template <typename T>
class Stack
{
	public:
		Stack();
		~Stack();

		void push(const T&);
		bool pop(T&);

		bool isEmpty();

	private:
		StackNode<T> *tos; // Top Of Stack
};

template <typename T>
Stack<T>::Stack()
{
	tos = NULL;
}

template <typename T>
Stack<T>::~Stack()
{
	T x;
	while (!isEmpty())
		pop(x);
}

template <typename T>
void Stack<T>::push(const T &x)
{
	StackNode<T> *tmp = new StackNode<T>();
	(*tmp).data = x;
	(*tmp).next = tos;
	tos = tmp;
}

// Pop function manipulates the input variable, and returns TRUE if successful
template <typename T>
bool Stack<T>::pop(T &x)
{
	if (tos != NULL) {
		StackNode<T> *tmp = tos;
		tos = (*tos).next;
		x = (*tmp).data;
		delete tmp;
		return true;
	}
	else
		return false;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return (tos == NULL);
}
