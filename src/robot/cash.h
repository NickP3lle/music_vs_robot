#define u32 unsigned int

#ifndef CASH_H
#define CASH_H
// Cash.h - Cash class definition
// it uses the singleton design pattern
// supports the following operations:
// 1. add a new cash item
// 2. remove a cash item
// 3. get the total amount of cash

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Cash {
public:
	static Cash& getInstance() {
		static Cash instance;
		return instance;
	}
	void add(u32 amount);
	bool remove(u32 amount);
	double getTotal();
private:
	Cash() {}
	Cash(Cash const&);
	void operator=(Cash const&);
	u32 totalCash;
};

#endif
