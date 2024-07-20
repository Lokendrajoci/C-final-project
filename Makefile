all: compile run

compile:
	g++ ./*.cpp -o main

run:
	./main