/*
 * RemotePlayer.h
 *
 *  Created on: Dec 5, 2017
 *      Author: oren
 */

#ifndef REMOTEPLAYER_H_
#define REMOTEPLAYER_H_

#include "Player.h"
#include <fstream>
#include <vector>

class RemotePlayer: public Player {
public:
	RemotePlayer(const char *serverIP, int serverPort);
	virtual ~RemotePlayer();
	virtual string get_type() const;
	void connectToServer();
	void sendNumber();
	void readFromServer(int buf[]);
	void writeToServer(int buf[]);
	int getClientSocket() const;
	void writeStringToServer(char *str);
	void readStringFromServer(char*str);


private:
	const char *serverIP;
	int serverPort;
	int clientSocket;
};

#endif /* REMOTEPLAYER_H_ */
