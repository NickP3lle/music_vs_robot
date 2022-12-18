#include "entity.h"
#include "../util/deque.h"
#include <vector>
#define PLAYGROUND_X 30
#define PLAYGROUND_Y 5

#ifndef PLAYGROUND_H
#define PLAYGROUND_H
class playground {
	private:
		static std::vector<Entity>* table_music[PLAYGROUND_X][PLAYGROUND_Y];
		static deque<Entity&>* table_robot[PLAYGROUND_X][PLAYGROUND_Y];
	public:
		playground() =delete;
		playground(playground&) =delete;
		playground& operator=(playground&) =delete;
};
#endif
