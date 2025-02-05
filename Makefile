all: run clean  

run: 
	g++ main.cpp
	./a.out

clean:
	rm a.out