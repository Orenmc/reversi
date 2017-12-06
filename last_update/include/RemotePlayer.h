/*
 * RemotePlayer.h
 *
 *  Created on: Dec 5, 2017
 *      Author: oren
 */

#ifndef REMOTEPLAYER_H_
#define REMOTEPLAYER_H_

#include "Player.h"

class RemotePlayer: public Player {
public:
	RemotePlayer(const char *serverIP, int serverPort);
	virtual ~RemotePlayer();
	virtual string get_type() const;
	void connectToServer();
	void sendNumber();

private:
	const char *serverIP;
	int serverPort;
	int clientSocket;
};

#endif /* REMOTEPLAYER_H_ */
