
compile:
	g++ -Wall -Wextra -g3 -std=c++17 ./src/main.cpp ./src/stopwatch.cpp ./src/utils.cpp ./src/menu.cpp -o ./output/main

run:
	./output/main