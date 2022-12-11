all: build run

ifndef pid
pid = 1
endif

build:
	g++ -std=c++17 solution.cpp -o solution

run:
	./solution < tests/$(pid).in 

test: solution
	./solution < tests/$(pid).in | diff -aur tests/$(pid).out -