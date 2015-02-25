#include <iostream>
#include <vector>
#include <list>

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
	deque<int>::iterator d_it; // iterator of deque
	
	int n;
	cout<<"Enter the elements of deque"<<endl;
	for(d_it=cont_1.begin(); d_it!=cont_1.end(); d_it++)
	{
		cin>>
	}

	vector<char>cont_2(5);
	//vector<int> container1(10, 4);
    //list<double> container2(5, 3.5);

	int result1 = sum(container1);  
    double result2 = sum(container2); 


	//cout<<"Enter the elements"<<endl;
	//for(int i=0; i<5; i++)
		//cin>>arr[i];

	//int elem_Sum = sum(v1);

	cout<<result1<<' '<<result2<<endl;

	

	return 0;

}
/*

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;

template< template<typename, typename> class C, typename E >

void print(const C<E, allocator<E>>& v) {
  copy(v.begin(), v.end(), ostream_iterator<E>(cout, "  "));
  cout << endl;
}

// “естова€ программа демонстрирует, как одна функци€ print()
// может использоватьс€ дл€ печати любого контейнера
// (если, конечно, он удовлетвор€ет требовани€м алгоритма
// copy() по наличию должных итераторов), содержащего элементы 
// любого типа.
int main() {

  int i[5] = { 1, 2, 3, 4, 5 };
  print< vector, int >( vector<int>(i, i + 5) );

  float f[5] = { .1, .2, .3, .4, .5 };
  print< vector, float >( vector<float>(f, f + 5) );

  char c[5] = { 'a', 'b', 'c', 'd', 'e' };
  print< deque, char >( deque<char>(c, c + 5) );

  char* s[5] = { "a1", "b2", "c3", "d4", "e5" };
  print< list, string >( list<string>(s, s + 5) );

  return 0;
}*/
