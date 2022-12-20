CC = g++
CFLAGS = -Wsuggest-override -Werror=suggest-override -std=c++2a
DEP = ../tool.o ../robot.o ../robotwtool.o ../../cash.o ../../entity.o ../../../util/independentfn.o testTool.o testRobot.o
ARG = ./main.cpp

compile: $(DEP)
	@$(CC) $(CFLAGS) $(DEP) $(ARG) -o $(basename $(ARG))

run: compile
	@./$(basename $(ARG))
	@ rm $(basename $(ARG))

%.o: %.cpp print 
	@$(CC) $(CFLAGS) $<  -o $@

clean:
	@rm *.o ../*.o ../../*.o ../../../util/*.o
