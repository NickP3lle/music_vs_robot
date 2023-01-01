CC = g++
DEP = ../cash.o ../entity.o ../robot/robot.o ../robot/tool.cpp ../robot/robotwtool.o ../music/music_instrument.o ../playground.o testCash.o testEntity.o testPlayground.o ../../util/independentfn.o 
CFLAGS = -Wsuggest-override -Werror=suggest-override -std=c++2a
arg = ./main.cpp

compile: $(DEP)
	@$(CC) $(DEP) $(CFLAGS) $(arg) -o $(basename $(arg))

run: compile
	@$(basename $(arg))
	@make clean
	@rm $(basename $(arg))

%.o: %.cpp 
	@$(CC) -c $< $(CFLAGS) -o $@

clean: 
	@rm *.o ../*.o ../../util/*.o
