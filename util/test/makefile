CC = g++
DEP = ../independentfn.o TestDeque.cpp testIndependetFn.cpp
CFLAGS = -Wsuggest-override -Werror=suggest-override -std=c++2a
arg = ./main.cpp

compile: $(DEP)
	@$(CC) $(DEP) $(CFLAGS) $(arg) -o $(basename $(arg))

run: compile
	@$(basename $(arg))

%.o: %.cpp 
	@$(CC) -c $< $(CFLAGS) -o $@

clean: 
	@rm *.o ../*.o $(basename $(arg))
