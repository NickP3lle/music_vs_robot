#include "entity.h"
#include "../util/deque.h"
#include <vector>
#define PLAYGROUND_X 30
#define PLAYGROUND_Y 5

#ifndef BATTLE_H
#define BATTLE_H
class playground {
	private:
		static std::vector<entity>* table[PLAYGROUND_X][PLAYGROUND_Y];
		static deque<entity&>* table_robot[PLAYGROUND_X][PLAYGROUND_Y];
	public:
		playground() =delete;
		playground(playground&) =delete;
		playground& operator=(playground&) =delete;
};
#endif
