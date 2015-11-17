#include<iostream>
#include<thread>
#include<chrono>
#include<vector>
#include<algorithm>

using namespace std;
using namespace chrono;

long long int sum = 0;

void countNumber(long long int begin, long long int end, long long int numb)
{
	for (long long int i = begin; i < end; i++)
	{
		if (!(numb%i))
		{
			sum += i;
		}
		
	}
}

int main()
{
	int amount;
	cout << "Enter the amount of threads" << endl;
	cin >> amount;

	long long int numb;
	cout << "Enter the number" << endl;
	cin >> numb;

	vector<thread> myVect;

	long long int work_Part = (numb - 1) / amount;
	int modulo = (numb - 1) % amount;

	long long int i = 1;

	auto start_Time = system_clock::now();

	for (int j = 0; j < amount; j++)
	{
		myVect.push_back(thread(countNumber, i, i + work_Part, numb));
		i += work_Part;
	}

	countNumber(i, numb, numb);
	for_each(myVect.begin(), myVect.end(), mem_fn(&std::thread::join));

	auto finish_Time = system_clock::now();
	auto differ = finish_Time - start_Time;

	if (sum == numb)
	{
		cout << "This number is perfect" << endl;
	}
	else
	{
		cout << "This number is not perfect" << endl;
	}

	cout << "Worktime: " << duration_cast<milliseconds>(differ).count() << endl;

	return 0;
}
