#include <stack>

template<class T, class C = std::stack < T > >
class Stack {
public:
   typedef typename T value_type;
   typedef typename C::size_type size_type;

   Stack();
   explicit Stack(const Stack&);
   
   bool empty()
   {
        return stack.empty();
   }
   size_type size()
   {
	return stack.size();
   }

   void push(const value_type&);
   void pop();
   value_type& top();
   const value_type& min();

protected:
   C stack;
   C min_stack;
};

template<class T, class C>
Stack<T, C>::Stack() : stack(), min_stack()
{
}

template<class T, class C>
Stack<T, C>::Stack(const Stack& obj) : stack(obj.stack), min_stack(obj.min_stack)
{
}

template<class T, class C>
typename Stack<T, C>::value_type& Stack<T, C>::top()
{
   return stack.top();
}

template<class T, class C>
void Stack<T, C>::push(const value_type& x)
{
   if(!stack.empty())
   {
	if(stack.top() >= x)
	{
              min_stack.push(x);
	}
   }
   else
   {
       min_stack.push(x);
   }
   stack.push(x);
}

template<class T, class C>
void Stack<T, C>::pop()
{
   	if(!stack.empty())
	{
	        if(stack.top()==min_stack.top())
		{
		       min_stack.pop();
		}
  	        stack.pop();
	}
}

template<class T, class C>
const typename Stack<T, C>::value_type& Stack<T, C>::min()
{
   	if(!stack.empty())
   	{
		return min_stack.top();
   	}
}
