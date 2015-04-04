
#include "Transport.h"

using namespace std;

int main()
{
	Transport myTransport;
	Svector_type myRoute_1;

	myRoute_1.push_back("Minsk");
	myRoute_1.push_back("Belarus");
	myRoute_1.push_back("Molodechno");

	myTransport.addRoute(33, "Bus", myRoute_1.begin(), myRoute_1.end());

	cout << "getRoutesByStop()" << endl;
	pair<Node_Iter, Node_Iter> iters_1 = myTransport.getRoutesByStop("Minsk");

	Node_Iter byStop;
	for (byStop = iters_1.first; byStop != iters_1.second; byStop++)
	{
		cout << *(byStop) << "; ";
	}

	cout << endl;

	myTransport.addStop("Minsk Sea");
	myTransport.addStop("Anusino");

	cout << "routeAmount(): " << myTransport.routeAmount() << endl;
	cout << "stopAmount(): " << myTransport.stopAmount() << endl;

	Svector_type myRoute_2;

	myRoute_2.push_back("Minsk");

	myTransport.addRoute(55, "Bus", myRoute_2.begin(), myRoute_2.end());


	////with random types//////
	Svector_type myRoute_3;

	myRoute_3.push_back("Minsk");
	myRoute_3.push_back("Baranovichi");
	myRoute_3.push_back("Brest");

	myTransport.addRoute(506, "Train", myRoute_3.begin(), myRoute_3.end());
	//myTransport.addRoute("506-A", "Train", myRoute_3.begin(), myRoute_3.end());

	Svector_type myRoute_4;

	myRoute_4.push_back("Minsk");
	myRoute_4.push_back("Oslo");

	myTransport.addRoute(184, "Plane", myRoute_4.begin(), myRoute_4.end());
	//myTransport.addRoute("TY-184", "Plane", myRoute_4.begin(), myRoute_4.end());

	cout << "maxRoutes(): " << myTransport.maxRoutes() << endl;

	cout << "getRoutesByType()" << endl;
	pair<keyNode_iter, keyNode_iter> iters_2 = myTransport.getRoutesByType("Bus", 15, 60);
	
	keyNode_iter byType;
	for (byType = iters_2.first; byType != iters_2.second; byType++)
	{
		cout << (byType->first).number << "; ";
	}

	/*Null_Iter stopIt;

	for (stopIt = iters_2.first; stopIt != iters_2.second; stopIt++)
		cout << (*stopIt) << "; ";

	cout << endl;*/

	myTransport.deleteStop("Minsk");
	cout << "After deleting the stop" << endl;
	cout << "routeAmount(): " << myTransport.routeAmount() << endl;
	cout << "stopAmount(): " << myTransport.stopAmount() << endl;

	myTransport.deleteRoute(33, "Bus");
	cout << "After deleting" << endl;
	cout << "routeAmount(): " << myTransport.routeAmount() << endl;
	cout << "stopAmount(): " << myTransport.stopAmount() << endl;

	system("PAUSE");
	return 0;
}
