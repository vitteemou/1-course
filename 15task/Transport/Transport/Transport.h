
#include "Node_Iter.h"

using namespace std;

class Transport
{
private:

	keyNode_type routes;
	keyString_type stops;

public:

	//Transport()

	void addRoute(int number, string type, Svector_iter begin, Svector_iter end);
	void deleteRoute(int number, string type);

	void addStop(string stop_name);
	void deleteStop(string stop_name);

	keyNode_type::size_type routeAmount()
	{
		return routes.size();
	}

	keyString_type::size_type stopAmount()
	{
		return stops.size();
	}

	pair<Node_Iter, Node_Iter> getRoutesByStop(string name);

	keyNode_pair getRoutesByType(string type, int x, int y);

	//pair<Null_Iter, Null_Iter> getNullStops();

	string maxRoutes();

};