#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <deque>

using namespace std;

template <template<typename, typename>class C, typename T>
T sum(C<T, allocator<T>> &cont)
{
	T elem_Sum = 0;
	C<T, allocator<T>>::iterator it;
	for(it=cont.begin(); it!=cont.end(); it++)
		elem_Sum = elem_Sum + (*it);

	return elem_Sum;
}

int main()
{
    
    deque<int> cont_1(5);
	
	int deque_Elem;
	cout<<"Enter the elements of deque"<<endl;
	for(int i=0; i<5; i++)
	{
		cin>>deque_Elem;
		cont_1.push_back(deque_Elem);
	}

	int result1 = sum(cont_1);  
	cout<<"Sum of deque's elements: "<<result1<<endl;
	
	vector<float> cont_2(4, 1.0001);
	float result2 = sum(cont_2);
	cout<<"Sum of vector's elements"<<result2<<endl;

	return 0;

}
