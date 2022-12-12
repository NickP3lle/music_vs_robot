#ifndef TOOL_H
#define TOOL_H
class tool {
	virtual void effect() =0;
};

class weapon: public tool {
};
#endif
