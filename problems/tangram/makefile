all: clean build run

build:
	g++ -std=c++17 solution.cpp -o solution -framework GLUT -framework OpenGL -Wno-deprecated-declarations

run:
	./solution

clean:
	rm -rf solution