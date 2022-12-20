CC = g++
DEP = ../cash.o ../entity.o testCash.o testEntity.o ../../util/independentfn.o
CFLAGS = -Wsuggest-override -Werror=suggest-override -std=c++2a
arg = ./main.cpp

compile: $(DEP)
	@$(CC) $(DEP) $(CFLAGS) $(arg) -o $(basename $(arg))

run: compile
	@$(basename $(arg))
	@rm $(basename $(arg))

%.o: %.cpp 
	@$(CC) -c $< $(CFLAGS) -o $@

clean: 
	@rm *.o ../*.o ../../util/*.o
