/*
 * RemoteGameLogic.h
 *
 *  Created on: Dec 5, 2017
 *      Author: oren
 */

#ifndef REMOTEGAMELOGIC_H_
#define REMOTEGAMELOGIC_H_

#include "GameLogic.h"
#include <string>
#include <vector>
#define END_OF_GAME -3
#define DISCONNECTED -4
#define NO_MOVE -1
#define INIT -2
using namespace std;

class RemoteGameLogic: public GameLogic {
public:
	RemoteGameLogic();
	virtual ~RemoteGameLogic();
	void connectAndCommand();
	void play_start_game();
	void play_join_game();
	int play_one_turn(Player* p1,int buf[]);
	void end_of_game();

private:
	void change_players();
	bool waiting_to_player;
	void print_list_games(char* str);
	vector<string> commandToVector(char* str);
};

#endif /* REMOTEGAMELOGIC_H_ */
