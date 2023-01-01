CC = g++
CFLAGS = -Wsuggest-override -Werror=suggest-override -std=c++2a
DEP = ../tool.o ../robot.o ../robotwtool.o ../../cash.o ../../entity.o ../../../util/independentfn.o testTool.o testRobot.o
ARG = ./main.cpp

%.o: %.cpp
	@$(CC) -c $(CFLAGS) $< -o $@

compile: $(DEP)
	@$(CC) $(CFLAGS) $(DEP) $(ARG) -o $(basename $(ARG))

run: compile
	@./$(basename $(ARG))
	@make clean

clean:
	@rm *.o ../*.o ../../*.o ../../../util/*.o $(basename $(ARG))
