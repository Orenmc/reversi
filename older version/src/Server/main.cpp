/*
 * main.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: snirhazan
 */

#include "Server.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
	Server server = Server();
	try {
		server.start();
	} catch (const char *msg) {
		cout << "Cannot start server. Reason: " << msg << endl;
		exit(-1);
	}
}
