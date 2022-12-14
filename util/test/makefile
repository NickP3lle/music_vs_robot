dependencies = ../deque.o
CC = g++
FLAGS =

test: $(dependencies)
	$(CC) $(FLAGS) main_test.cpp $(dependencies) -o main_test
	./main_test

%.o: %.cpp
	$(CC) $< $(FLAGS) -o $@

clear:
	rm *.o
