all: run clean  

run: 
	g++ main.cpp -lncurses
	./a.out

clean:
	rm a.out

