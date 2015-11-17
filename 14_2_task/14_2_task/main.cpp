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
