all:
	g++ -c *.cpp
	g++ *.o -o game.x86 -lSDL2 -lSDL2_ttf
