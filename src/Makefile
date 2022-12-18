CC = g++
MUSIC = music/music_instrument.o music/flute.o music/trumpet.o music/drum.o music/violin.o music/saxophone.o music/levelUpTest.cpp
ROBOT = robot/robot.o robot/tool.o
MAIN_TARGET = entity.o cash.o 

%.o: %.c
	${CC} -c $< -o $@

music_test: ${MUSIC} ${MAIN_TARGET}
	${CC} ${MUSIC} ${MAIN_TARGET} -o $@

robot_test: ${MAIN_TARGET} ${ROBOT}
	${CC} ${MAIN_TARGET} ${ROBOT} -o $@

clear:
	rm *.o */*.o music_test robot_test