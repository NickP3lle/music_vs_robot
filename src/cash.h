#define u32 unsigned int

#ifndef CASH_H
#define CASH_H

class cash {
	private:
		static u32 money;
	public:
		cash() =delete;
		cash(cash&) =delete;
		cash& operator=(cash&) =delete;
		static void in(u32);
		static bool out(u32); // false if there is not enough money
		static u32 get_money();
};
#endif
