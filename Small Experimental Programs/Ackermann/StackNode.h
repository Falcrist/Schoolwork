// StackNode.h
// class template for the stack's nodes

template <typename T>
class StackNode
   {
      public:
               StackNode();
               StackNode(T);


               StackNode *next;
               T data;
   };

template <typename T>
StackNode<T>::StackNode()
{
    next = NULL;
}

template <typename T>
StackNode<T>::StackNode(T x)
{
    data = x;
    next = NULL;
}
