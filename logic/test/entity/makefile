CC = g++

CFLAGS = -target arm64-apple-macos11 -mmacosx-version-min=11.0 -std=c++2a

DEP = test_tool.o ../../util/independentfn.o ../../entity/tool.o \
	  ../../entity/damage.o ../../entity/enemy.o test_enemy.o \
	  ../../entity/entity.o ../../entity/player.o test_player.o \
	  test_enemywtool.o ../../entity/enemywtool.o

arg = ./main.cpp

compile: $(DEP)
	$(CC) $(CFLAGS) $(DEP) $(arg) -o $(basename $(arg))

run: compile
	$(basename $(arg))

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o ../../util/*.o ../../entity/*.o

