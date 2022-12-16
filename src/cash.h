#define u32 unsigned int

#ifndef CASH_H
#define CASH_H
// class Cash:
//  - represents a cash register
//  - has only one balance
//  - can add and remove money
//  - can return the actual balance

class Cash {
	public:
		Cash() =delete;
		Cash(const Cash& cash) =delete;
		Cash& operator=(const Cash& cash) =delete;

		static Cash* getInstance() { return instance; }
		void add(u32 amount) { balance += amount; }
		void remove(u32 amount) { balance -= amount; }
		u32 get() { return balance; }
	private:
		static Cash* instance;
		u32 balance;
};
#endif
