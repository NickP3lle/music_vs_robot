CC = g++

DEP = game/cash.o game/entity.o game/playground.o game/timer.o \
	  robot/robot.o robot/robotwtool.o robot/tool.o \
	  music/music_instrument.o util/independentfn.o

arg = ./main.cpp

compile: $(DEP)
	$(CC) $(DEP) $(arg) -o $(basename $(arg))

run: compile
	$(basename $(arg))

%.o: %.cpp
	$(CC) -c $< -o $@
