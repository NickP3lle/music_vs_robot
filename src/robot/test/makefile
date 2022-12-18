CC = g++
CFLAGS = -target arm64-apple-macos11 -mmacosx-version-min=11.0 -Wsuggest-override -Werror=suggest-override -std=c++2a
DEP = ../../cash.o ../../entity.o ../tool.o ../robot_v2.o  
ARG = ./testRobot.cpp

compile: $(DEP)
	@$(CC) $(CFLAGS) $(ARG) $(DEP) -o $(basename $(ARG))

help:
	echo "Help:\n"
	cat /Users/carlorosso/.config/Makefile

run: compile
	@$(basename $(arg))

%.o: %.cpp print 
	@$(CC) $< $(CFLAGS) -o $@

clean:
	rm *.o ../*.o ../../*.o ../../../util/*.o
