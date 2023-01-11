CC = g++
CFLAGS = -Wsuggest-override -Werror=suggest-override -std=c++2a
MUSIC = music/music_instrument.o music/levelUpTest.o
MAIN_TARGET = entity.o cash.o 

%.o: %.cpp
	@${CC} $(CFLAGS) -c $< -o $@

test_music: ${MAIN_TARGET} ${MUSIC}
	@${CC} $(CFLAGS) ${MAIN_TARGET} ${MUSIC} -o $@

test_robot: 
	@(cd robot/test; make run)

clean:
	@rm *.o music/*.o
