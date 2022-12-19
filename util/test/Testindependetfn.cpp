#include "../independentfn.cpp"

bool TestRandomInt() {
	for (int _ = 0; _ < 100; _++) {
		int a = randomInt(43, 40);
		if (a < 40 || a > 43)
			return false;
	}
	return true;
}
