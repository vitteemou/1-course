
#include "Transport.h"
//#include "Null_Iter.h"

using namespace std;

//////////General////////////
istream& operator >> (istream& is, Node& obj)
{
	is >> obj.number >> obj.type;
	return is;
}


ostream& operator << (ostream& os, const Node& obj)
{
	os << obj.number << ' ' << obj.type;
	return os;
}

/*bool operator <(const Node& obj1, const Node& obj2)
{
	if (obj1.type == obj2.type)
		return (obj1.number < obj2.number);
	else
		return (obj1.type < obj2.type);
}*/

bool operator <(const Node obj1, const Node obj2)
{
	if (obj1.type == obj2.type)
		return (obj1.number < obj2.number);
	else
		return (obj1.type < obj2.type);
}


bool operator ==(const Node& obj1, const Node& obj2)
{
	return ((obj1.number == obj2.number) && (obj1.type == obj2.type));
}

bool operator !=(const Node& obj1, const Node& obj2)
{
	return ((obj1.number != obj2.number) || (obj1.type != obj2.type));
}


////////////Transport//////////////

void Transport::addRoute(int number, string type, Svector_iter begin, Svector_iter end)
{
	static Node obj;
	Svector_type v;
	Svector_iter it;

	obj.number = number;
	obj.type = type;

	for (it = begin; it != end; it++)
	{
		v.push_back(*it);
	}

	routes.insert(pair<Node, vector<string> >(obj, v));

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

void Transport::deleteRoute(int number, string type)
{
	Node obj;
	obj.number = number;
	obj.type = type;

	routes.erase(obj);
}


void Transport::addStop(string name)
{
	Nvector_type v;
	stops.insert(pair<string, vector<Node*> >(name, v));
}


void Transport::deleteStop(string name)
{
   Nvector_iter stopIt = stops[name].begin();

   while (stopIt != stops[name].end() && (!routes[**stopIt].empty()))
   {
       Node obj = (**stopIt);

       if((routes[obj]).size() == 1)
       {
           Nvector_iter term = stopIt;
           deleteRoute((**stopIt).number, (**stopIt).type);
           stopIt = term;
       }
       else
       {
           Svector_iter routeIt;
           routeIt = find(routes[obj].begin(), routes[obj].end(), name);
           routes[obj].erase(routeIt);
       }
   }
        stopIt++;
        stops.erase(name);

}


pair<Node_Iter, Node_Iter> Transport::getRoutesByStop(string name)
{
	Node_Iter begin (stops[name].begin());
	Node_Iter end (stops[name].end());

	return make_pair(begin, end);
}

keyNode_pair Transport::getRoutesByType(string type, int x, int y)
{
	Node firstNode(x, type);
	Node lastNode(y, type);
	
	keyNode_iter it = routes.begin();


	while ((it->first < firstNode) && (it != routes.end()))
	{
		cout << it->first << ' ';
		it++;
	}

	keyNode_iter begin = it;

	it = routes.end();
	it--;

	while ((lastNode < it->first) && (it != routes.begin()))
		it--;

	it++;
	keyNode_iter end = it;

	return make_pair(begin, end);

}

/*
template <class T>
pair<Null_Iter, Null_Iter> Transport::getNullStops()
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

}*/

template <class T>
string Transport::maxRoutes()
{
	map<int, string> sizeMap;
	keyString_iter it;
	for (it = stops.begin(); it != stops.end(); it++)
	{
		int size = (it->second).size();
		sizeMap.insert(pair<int, string>(size, it->first));
	}

	map<int, string>::iterator it_m;
	it_m = sizeMap.end();
	it_m--;


	return (it_m->second);
}