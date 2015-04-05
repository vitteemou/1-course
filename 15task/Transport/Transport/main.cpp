
#include "Transport.h"

using namespace std;

int main()
{
	Transport<string> myTransport;
	Svector_type myRoute_1;

	myRoute_1.push_back("Minsk");
	myRoute_1.push_back("Belarus");
	myRoute_1.push_back("Molodechno");

	myTransport.addRoute("33", "Bus", myRoute_1.begin(), myRoute_1.end());

	myTransport.addStop("Anusino");

	cout << "routeAmount(): " << myTransport.routeAmount() << endl;
	cout << "stopAmount(): " << myTransport.stopAmount() << endl;

	Svector_type myRoute_2;

	myRoute_2.push_back("Minsk");

	myTransport.addRoute("55", "Bus", myRoute_2.begin(), myRoute_2.end());


	////with random types//////
	Svector_type myRoute_3;

	myRoute_3.push_back("Minsk");
	myRoute_3.push_back("Baranovichi");
	myRoute_3.push_back("Brest");

	//myTransport.addRoute(505, "Train", myRoute_3.begin(), myRoute_3.end());
	myTransport.addRoute("506-A", "Train", myRoute_3.begin(), myRoute_3.end());

	Svector_type myRoute_4;

	myRoute_4.push_back("Minsk");
	myRoute_4.push_back("Oslo");

	//myTransport.addRoute(1840, "Plane", myRoute_4.begin(), myRoute_4.end());
	myTransport.addRoute("TY-184", "Plane", myRoute_4.begin(), myRoute_4.end());
	cout << endl;

	cout << "getRoutesByStop()" << endl;
	pair<Transport<string>::Node_Iter, Transport<string>::Node_Iter> iters_1 = myTransport.getRoutesByStop("Minsk");

	Transport<string>::Node_Iter byStop;
	for (byStop = iters_1.first; byStop != iters_1.second; byStop++)
		cout << *(byStop) << "; ";

	cout << endl;
	
	cout << "maxRoutes(): " << myTransport.maxRoutes() << endl;

	cout << "getRoutesByType()" << endl;
	pair<Transport<string>::keyNode_iter, Transport<string>::keyNode_iter> iters_2 = myTransport.getRoutesByType("Train", "15", "600");
	
	Transport<string>::keyNode_iter byType;
	for (byType = iters_2.first; byType != iters_2.second; byType++)
		cout << (byType->first).number << "; ";

	cout << endl;

	cout << "getNullStops()" << endl;
	pair<Transport<string>::Null_Iter, Transport<string>::Null_Iter> iters_3 = myTransport.getNullStops();

	Transport<string>::Null_Iter myNulls;
	for (myNulls = iters_3.first; myNulls != iters_3.second; ++myNulls)
		cout << *(myNulls) << "; ";

	cout << endl;

	cout << "Before deleting of the stop" << endl;
	cout << "routeAmount(): " << myTransport.routeAmount() << endl;
	cout << "stopAmount(): " << myTransport.stopAmount() << endl;
	cout << endl;

	myTransport.deleteStop("Minsk");

	cout << "After deleting of the stop" << endl;
	cout << "routeAmount(): " << myTransport.routeAmount() << endl;
	cout << "stopAmount(): " << myTransport.stopAmount() << endl;
    cout << endl;

	myTransport.deleteRoute("33", "Bus");

	cout << "After deleting of the route" << endl;
	cout << "routeAmount(): " << myTransport.routeAmount() << endl;
	cout << "stopAmount(): " << myTransport.stopAmount() << endl;

	system("PAUSE");
	return 0;
}
