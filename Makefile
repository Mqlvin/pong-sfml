all: clean build clean_objects

# used on my system to fix issues due to the window manager
fix_float:
	bspc rule -a SFML state=floating center=true

clean:
	rm -f ./out
	rm -rf *.o

clean_objects:
	rm -rf *.o

build: main.o player.o ball.o line.o score.o
	g++ main.o player.o ball.o line.o score.o -o ./out -lsfml-graphics -lsfml-window -lsfml-system

main.o:
	g++ -c ./src/main.cpp

player.o:
	g++ -c ./src/player/player.cpp

ball.o:
	g++ -c ./src/ball/ball.cpp

line.o:
	g++ -c ./src/ui/line.cpp

score.o:
	g++ -c ./src/ui/score.cpp