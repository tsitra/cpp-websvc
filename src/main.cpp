// main.cpp : Defines the entry point for the application.
//

#include "main.h"

using namespace std;

class Service {
public: 
	void doThing() {
		cout << "Hello CMake::Service::doThing()" << endl;
	}
};

int main()
{
	Service svc;
	svc.doThing();
	return 0;
}

