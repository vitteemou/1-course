
#include "Transport.h"

using namespace std;

//////////General////////////



/*
template<class T, class C>
bool operator <(const C& obj1, const C& obj2)
{
	if (obj1.type == obj2.type)
		return (obj1.number < obj2.number);
	else
		return (obj1.type < obj2.type);
}*/


////////Node_Iter//////////

/*template<class T, class C>
Transport<T,C>::Node_Iter::Node_Iter() : basicIter<T,C>()
{
}

template<class T, class C>
Transport<T, C>::Node_Iter::Node_Iter(Nvector_iter& basic)
{
		basicIter = basic;
}

template<class T, class C>
T Transport<T, C>::Node_Iter:: operator *()
{
		return (**basicIter).number;
}

template<class T, class C>
//typedef Transport::Node_Iter Node_Iter;

const typename (Transport<T, C>::Node_Iter)& Transport<T, C>::Node_Iter:: operator ++(int)
{
		++basicIter;
		return *this;
}

template<class T, class C>
bool Transport<T, C>::Node_Iter:: operator == (Node_Iter& obj)
{
		return (basicIter == obj.basicIter);
}

template<class T, class C>
bool Transport<T, C>::Node_Iter:: operator != (Node_Iter& obj)
{
		return (basicIter != obj.basicIter);
}*/

////////////Transport//////////////
/*template<class T, class C>

void Transport<T,C>::addRoute(T number, string type, Svector_iter begin, Svector_iter end)
{
	static C obj;
	Svector_type v;
	Svector_iter it;

	obj.number = number;
	obj.type = type;

	for (it = begin; it != end; it++)
	{
		v.push_back(*it);
	}

	routes.insert(pair<C, vector<string> >(obj, v));

	sort(v.begin(), v.end());

	for (it = v.begin(); it != v.end(); it++)
	{
		if (stops.count(*it))
			stops[*it].push_back(&obj);
		else
		{
			Nvector_type v_node;
			v_node.push_back(&obj);
			stops.insert(pair<string, Nvector_type>(*it, v_node));
		}
	}

}
/*
template<class T, class C>
void Transport<T,C>::deleteRoute(T number, string type)
{
	C obj;
	obj.number = number;
	obj.type = type;

	routes.erase(obj);
}

template<class T, class C>
void Transport<T,C>::addStop(string name)
{
	Nvector_type v;
	stops.insert(pair<string, vector<C_ptr> >(name, v));
}

template<class T, class C>
void Transport<T,C>::deleteStop(string name)
{
   Nvector_iter stopIt = stops[name].begin();

   while (stopIt != stops[name].end() && (!routes[**stopIt].empty()))
   {
	   cout << "Circle" << endl;
	   C obj = (**stopIt);

       if((routes[obj]).size() == 1)
       {
           Nvector_iter term = stopIt;
           deleteRoute(obj.number, obj.type);
           stopIt = term;
		   cout << "ok1" << endl;
       }
       else
       {
           Svector_iter routeIt;
           routeIt = find(routes[obj].begin(), routes[obj].end(), name);
           routes[obj].erase(routeIt);
		   cout << "ok2" << endl;
       }
   }
        stopIt++;
        stops.erase(name);

}


/*
template<class T, class C>
pair<Null_Iter, Null_Iter> Transport<T,C>::getNullStops()
{
	
	keyString_iter basicIt = stops.begin();
	Null_Iter it(basicIt);

	it = stops.begin();
	//it++;
	//cout << *it << endl;
	//it++;
	//cout << *it << endl;
	Null_Iter begin = it;

	while(it != stops.end())
	{
	    cout<<"Circle"<<endl;
	    it++;
	}

	Null_Iter end = it;

	return make_pair(begin, end);

}

template<class T, class C>
string Transport<T,C>::maxRoutes()
{
	map<T, string> sizeMap;
	keyString_iter it;
	for (it = stops.begin(); it != stops.end(); it++)
	{
		int size = (it->second).size();
		sizeMap.insert(pair<T, string>(size, it->first));
	}

	map<T, string>::iterator it_m;
	it_m = sizeMap.end();
	it_m--;


	return (it_m->second);
}*/