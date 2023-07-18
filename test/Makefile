CC = g++
CFLAGS = -Wsuggest-override -Werror=suggest-override -std=c++2a
MUSIC = music/music_instrument.o
MAIN_TARGET = entity.o cash.o 

%.o: %.cpp
	@${CC} $(CFLAGS) -c $< -o $@

all: 
#	@make test_music
#	@echo ""
	@make test_robot
	@echo ""
	@make test_src

test_music:
	@(cd music/test; make run)
test_robot: 
	@(cd robot/test; make run)

test_src:
	@(cd test; make run)

clean:
	@rm *.o music/*.o robot/*.o test/*.o