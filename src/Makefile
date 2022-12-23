CC = g++
MUSIC = music/music_instrument.o music/flute.o music/trumpet.o music/drum.o music/violin.o music/saxophone.o music/levelUpTest.cpp
ROBOT = robot/robot.o robot/tool.o
MAIN_TARGET = entity.o cash.o 
# FLAG = -Wc++11-extensions

%.o: %.cpp
	${CC} -c $< -o $@

music_test: ${MAIN_TARGET} ${MUSIC}
	${CC} ${MAIN_TARGET} ${MUSIC} -o $@

robot_test: 
	@(cd robot/test; make run)

clear:
	rm *.o */*.o music_test robot_test
