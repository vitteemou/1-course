
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <vector>

using namespace std;

///////////Node///////////
template<class T>
struct Node
{

	Node(){}
	Node(T n, string t)
	{
		this->number = n;
		this->type = t;
	}

	T number;
	string type;
};

template<class T>
bool operator <(const Node<T> obj1, const Node<T> obj2)
{
	if (obj1.type == obj2.type)
		return (obj1.number < obj2.number);
	else
		return (obj1.type < obj2.type);
}

template<class T>
istream& operator >> (istream& is, Node<T>& obj)
{
	is >> obj.number >> obj.type;
	return is;
}

template<class T>
ostream& operator << (ostream& os, const Node<T>& obj)
{
	os << obj.number << ' ' << obj.type;
	return os;
}

template<class T>
bool operator ==(const Node<T>& obj1, const Node<T>& obj2)
{
	return ((obj1.number == obj2.number) && (obj1.type == obj2.type));
}

template<class T>
bool operator !=(const Node<T>& obj1, const Node<T>& obj2)
{
	return ((obj1.number != obj2.number) || (obj1.type != obj2.type));
}

typedef vector<string> Svector_type;
typedef vector<string>::iterator Svector_iter;



///////////Transport//////////
 
template<class T, class C = Node<T> >
class Transport
{

public:

	typedef typename const C* C_ptr;
	typedef typename vector<C_ptr> Nvector_type;
	typedef typename vector<C_ptr>::iterator Nvector_iter;

	typedef typename map<C, vector<string> > keyNode_type;           //for
	typedef typename map<C, vector<string> >::iterator keyNode_iter; //routes

	typedef typename map<string, Nvector_type> keyString_type;           //for
	typedef typename map<string, Nvector_type>::iterator keyString_iter; //stops


	///////////Node_Iter///////////
	class Node_Iter
	{

	public:
		
		   Node_Iter() : basicIter()
	       {
	       }

		  
		   Node_Iter(Nvector_iter& basic)
		   {
			   basicIter = basic;
		   }

		   
		   T operator *()
		   {
			   return (**basicIter).number;
		   }

		   const typename Node_Iter& operator ++(int)
		   {
			   ++basicIter;
			   return *this;
		   }

		   bool operator == (Node_Iter& obj)
		   {
			   return (basicIter == obj.basicIter);
		   }

		   bool operator != (Node_Iter& obj)
		   {
			   return (basicIter != obj.basicIter);
		   }

	private:
		Nvector_iter basicIter;

	}; 


	///////////////Null_Iter/////////////

	class Null_Iter
	{
	public:


		Null_Iter() : basicIter()
		{
		}

		Null_Iter(keyString_iter& basic)
		{
			basicIter = basic;
		}

		string operator *()
		{
			return (basicIter->first);
		}

		Null_Iter& operator++ ()
		{
		  while (!((basicIter->second).empty()))
		      ++basicIter;
		  
		  ++basicIter;
		   return *this;
		}

		Null_Iter& operator =(keyString_iter& basicObj)
		{
			this->basicIter = basicObj;
			return *this;
		}

		Null_Iter& operator =(const keyString_iter& basicObj)
		{
			this->basicIter = basicObj;
			return *this;
		}

		bool operator ==(keyString_iter basicObj)
		{
			return (basicIter == basicObj);
		}
		bool operator !=(keyString_iter basicObj)
		{
			return (basicIter != basicObj);
		}

		bool operator ==(Null_Iter obj)
		{
			return (basicIter == obj.basicIter);
		}


		bool operator !=(Null_Iter obj)
		{
			return (basicIter != obj.basicIter);
		}

		/*
		bool operator ==(keyString_iter basicObj)
		{
		return (basicIter == basicObj);
		}


		bool operator !=(keyString_iter basicObj)
		{
		return (basicIter != basicObj);
		}*/

	private:
		keyString_iter basicIter;
	};

	////////////////Transport//////////////


	Transport(){}
	
	void addRoute(T number, string type, Svector_iter begin, Svector_iter end)
	{
		C obj;
		Svector_type v;
		Svector_iter it;

		obj.number = number;
		obj.type = type;

		for (it = begin; it != end; it++)
		{
			v.push_back(*it);
		}

		routes.insert(pair<C, vector<string> >(obj, v));

		keyNode_iter mapIt = routes.find(obj);
		
		const C& adress = mapIt->first;
		
		sort(v.begin(), v.end());

		for (it = v.begin(); it != v.end(); it++)
		{
			if (stops.count(*it))
				stops[*it].push_back(&adress);
			else
			{
				Nvector_type v_node;
				v_node.push_back(&adress);
				stops.insert(pair<string, Nvector_type>(*it, v_node));
			}
		}

	}
	void deleteRoute(T number, string type)
    {
			C obj;
			obj.number = number;
			obj.type = type;

			routes.erase(obj);
	}

	void addStop(string name)
	{
		Nvector_type v;
		stops.insert(pair<string, vector<C_ptr> >(name, v));
	}

	void deleteStop(string name)
	{
		Nvector_iter stopIt = stops[name].begin();
		
		while (stopIt != stops[name].end())// && (!routes[**stopIt].empty()))
		{
			C obj = (**stopIt);

			if ((routes[obj]).size() == 1)
			{
				Nvector_iter term = ++stopIt;
				deleteRoute(obj.number, obj.type);
				stopIt = term;
			}
			else
			{
				Svector_iter routeIt;
				routeIt = find(routes[obj].begin(), routes[obj].end(), name);
				routes[obj].erase(routeIt);
				stopIt++;
			}
		}
		
		stops.erase(name);

	}

	typename keyNode_type::size_type routeAmount()
	{
		return routes.size();
	}

	typename keyString_type::size_type stopAmount()
	{
		return stops.size();
	}

	typename pair<Node_Iter, Node_Iter> getRoutesByStop(string name)
	{
		Node_Iter begin = stops[name].begin();
		Node_Iter end = stops[name].end();

		return make_pair(begin, end);
	}

	typename pair<keyNode_iter, keyNode_iter> Transport<T,C>::getRoutesByType(string type, T x, T y)
	{


		keyNode_iter it = routes.begin();
		while ((it->first).type != type)
			it++;

		while (((it->first).number < x) && (it != routes.end()) && ((it->first).type == type))
			it++;

		keyNode_iter begin = it;

		it = routes.end();
		it--;

		while ((y < (it->first).number) && (it != routes.begin()) && ((it->first).type == type))
			it--;

		it++;
		keyNode_iter end = it;

		return make_pair(begin, end);

	}

	typename pair<Null_Iter, Null_Iter> Transport<T, C>::getNullStops()
	{
		keyString_iter it;
		it = stops.begin();

		while (!(it->second).empty())
			it++;

		Null_Iter begin = it;

		it = stops.end();
		it--;

		while (!(it->second).empty())
			it--;

		it++;
		Null_Iter end = it;

		return make_pair(begin, end);
	}

	string maxRoutes()
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

private:

	keyNode_type routes;
	keyString_type stops;
};