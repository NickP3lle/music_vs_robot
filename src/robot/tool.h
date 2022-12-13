#include "../character.h"
#ifndef TOOL_H
#define TOOL_H
class tool: public character {
	private:
		unsigned int speed;
	virtual void effect() =0;
};
#endif
