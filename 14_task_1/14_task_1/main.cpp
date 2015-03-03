
/*Вам даны результаты решения заданий участниками на одном из соревнований. Они вводятся в консоль построчно, 
где в каждой строке содержится имя участника, количество решенных задач и суммарное затраченное время в минутах.
Выведите список имен участников, отсортированный по занятому месту, начиная с первого. Место участника определяется
по количеству решенных задач, а при их равенстве - выше тот участник, кто затратил меньшее время на решения задач.
При равенстве обоих параметров, выше располагается тот участник, который идет раньше во входных данных.
Для сортировки использовать стандартные функции STL.*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct Competitor
{
	string name;
	int problems; // amount of problems
	int time; //in minutes
};

istream& operator >> (istream& is, Competitor& obj)
{
	is>>obj.name>>obj.problems>>obj.time;
	return is;
}


ostream& operator << (ostream& os, Competitor& obj)
{	
	os<<obj.name<<' '<<obj.problems<<' '<<obj.time<<endl;
	return os;
}

bool sortCompetitors(Competitor& obj1, Competitor& obj2)
{
	if(obj1.problems==obj2.problems)
		return (obj1.time < obj2.time);
	else
	   return (obj1.problems > obj2.problems);
}

int main()
{
	int size;
	cout<<"Enter the amount of competitors"<<endl;
	cin>>size;

	Competitor compet;
	vector<Competitor> v2(size);

	cout<<"Enter the competitors"<<endl;
	for(int i=0; i<size; i++)
		cin>>v2[i];
	cout<<endl;

	sort(v2.begin(), v2.end(), sortCompetitors);

	cout<<"Sorted competitors: "<<endl;
	for(int i=0; i<size; i++)
		cout<<i+1<<" place: "<<v2[i];

	return 0;
}