/*
 * RemoteGameLogic.h
 *
 *  Created on: Dec 5, 2017
 *      Author: oren
 */

#ifndef REMOTEGAMELOGIC_H_
#define REMOTEGAMELOGIC_H_

#include "GameLogic.h"

class RemoteGameLogic: public GameLogic {
public:
	RemoteGameLogic();
	virtual ~RemoteGameLogic();
	int play_one_turn(Player* p1);
};

#endif /* REMOTEGAMELOGIC_H_ */
