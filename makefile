all: imacwars

imacwars : main.o display.o player.o functions.o units.o rules.o
	g++ main.o display.o player.o functions.o units.o rules.o -o imacwars
	@echo Compilation terminee

main.o : main.cpp
	g++ -c main.cpp

display.o : display.cpp
	g++ -c display.cpp

player.o : player.cpp
	g++ -c player.cpp

functions.o : functions.cpp
	g++ -c functions.cpp

units.o : units.cpp
	g++ -c units.cpp

rules.o : rules.cpp
	g++ -c rules.cpp
