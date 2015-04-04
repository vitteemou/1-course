
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Node
{
	Node(){}
	Node(int n, string t)
	{
		this->number = n;
		this->type = t;
	}
	
	int number;
	string type;
};

typedef vector<string> Svector_type;
typedef vector<Node*> Nvector_type;

typedef vector<string>::iterator Svector_iter;
typedef vector<Node*>::iterator Nvector_iter;

typedef map<Node, vector<string> > keyNode_type;  //for routes
typedef map<string, vector<Node*> > keyString_type;  //for stops

typedef map<Node, vector<string> >::iterator keyNode_iter; //for routes
typedef map<string, vector<Node*> >::iterator keyString_iter; //for stops 

typedef pair<keyString_iter, keyString_iter> keyString_pair;
typedef pair<keyNode_iter, keyNode_iter> keyNode_pair;

typedef pair<Nvector_iter, Nvector_iter> Nvector_pair;
typedef pair<Svector_iter, Svector_iter> Svector_pair;

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

	/* string operator ->()
	{
	return (basicIter->first);
	}*/

	string operator *()
	{
		return (basicIter->first);
	}

	/*Null_Iter& operator++ (int)
	{
		while ((basicIter->second).size() != 0)
		    basicIter++;

		Null_Iter* term = this;
		basicIter++;

		return *term;
	}*/

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


typedef pair<Null_Iter, Null_Iter> nullmap_pair;