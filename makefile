all:
	mkdir -p bin
	g++ -o bin/game scenario.cpp main.cpp

scenario:
	mkdir -p obj
	g++ -c scenario.cpp

main:
	mkdir -p obj
	g++ -c main.cpp

Obj:
	make scenario
	make main

clean:
	rm obj/*.o bin/game