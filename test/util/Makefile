CC = g++
CFLAGS = -Wsuggest-override -Werror=suggest-override -std=c++2a
DEP = ../../util/dataManager.o ../../game/timer.o ../../game/cash.o ../../game/playground.o ../../game/entity.o ../../music/music_instrument.o ../../robot/robot.o ../../robot/tool.o ../../robot/robotwtool.o ../../util/independentfn.o Testdatamanager.o 
ARG = ./main.cpp

%.o: %.cpp
	@$(CC) -c $(CFLAGS) $< -o $@

compile: $(DEP)
	@$(CC) $(CFLAGS) $(DEP) $(ARG) -o $(basename $(ARG))

run: compile
	@./$(basename $(ARG))

clean:
	@rm *.o ../*.o ../../*.o ../../util/*.o ../../music/*.o ../../robot/*.o ../../game/*.o $(basename $(ARG))