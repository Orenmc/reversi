/*
 * JoinCommand.h
 *
 *  Created on: Jan 2, 2018
 *      Author: oren
 */

#ifndef JOINCOMMAND_H_
#define JOINCOMMAND_H_


#include "Command.h"
#include <iostream>

class JoinCommand: public Command {
public:

	virtual void execute(vector<string> args,vector<GameRoom> &GR,pthread_mutex_t lock, int socket) {
		char result[100] = "notgood";
		int i;
		pthread_mutex_lock(&lock);
		unsigned size =  GR.size();


		for( i =0 ; (unsigned)i < size; i++){
			if(GR[i].getName() == args[1]){
				strcpy(result,"good-join");
				GR[i].setSid2(socket);
				GR[i].setCounter(2);
				break;
			}
		}
		int clientSocket1 = GR[i].getSid1();
		GR.erase(GR.begin()+i);

		pthread_mutex_unlock(&lock);

		int n = write(socket,&result,sizeof(result));
		if(n== -1) {
			cout << "Error write to socket" << endl;
		}

		n = write(clientSocket1,&result,sizeof(result));
		if(n== -1) {
			cout << "Error write to socket" << endl;
		}

		handle(clientSocket1, socket);


		close(socket);
		close(clientSocket1);
	}
	void handle (int clientSocket1, int clientSocket2) {
		cout << "entered handle 2 clients" << endl;
		int n;
		int buf[2];
		while (true) {

			//read from player 1
			cout << "read from 1 client:" << endl;
			n = read(clientSocket1, &buf, sizeof(buf));
			if (n == -1) {
				cout << "Error reading move from client1" << endl;
				break;
			}
			if (n == 0) {
				cout << "Client1 disconnected" << endl;
				break;
			}

			n = write(clientSocket2, &buf, sizeof(buf));

			// Write the result back to the client
			if (n == -1) {
				cout << "Error writing move to client2" << endl;
				break;
			}
			if (n == 0) {
				cout << "Client2 disconnected" << endl;
				break;
			}

			n = read(clientSocket2, &buf, sizeof(buf));

			if (n == -1) {
				cout << "Error read move from client2" << endl;
				break;
			}
			if (n == 0) {
				cout << "Client2 disconnected" << endl;
				break;
			}
			n = write(clientSocket1, &buf, sizeof(buf));


		}
	}


};



#endif /* JOINCOMMAND_H_ */
