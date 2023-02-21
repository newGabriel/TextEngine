all:
	mkdir -p bin
	g++ -o bin/game scenario.cpp maze.cpp main.cpp

scenario:
	mkdir -p obj
	g++ -c scenario.cpp

maze:
	mkdir -p obj
	g++ -c maze.cpp

main:
	mkdir -p obj
	g++ -c main.cpp

Obj:
	make scenario
	make maze
	make main

clean:
	rm obj/*.o bin/game