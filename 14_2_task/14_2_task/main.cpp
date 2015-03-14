/*Реализовать стек с дополнительной функцией value_type& min() как адаптер над обычным стеком, в качестве которого может выступать любой стек,
а не только std::stack. Функция min() должна возвращать ссылку на  минимальный элемент в стеке, для пустого стека ее значение не определено.
Функции push, pop, top и min должны работать за O(1). Сигнатура класса должна быть следующей:
template<class T, class C = std::stack<T> > class Stack*/

#include <iostream>
#include <stack>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> st;

	st.push(5);
	st.push(7);
	st.push(3);
	st.push(6);

	cout<<"1) Stack top(): "<<st.top()<<endl;
	cout<<"2) Stack min(): "<<st.min()<<endl;
	cout<<endl;

	st.pop();
	st.pop();

	cout<<"After pop(): "<<endl;
	cout<<"1) Stack top(): "<<st.top()<<endl;
	cout<<"2) Stack min(): "<<st.min()<<endl;
	cout<<endl;

	return 0;
}