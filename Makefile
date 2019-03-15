main: main.o
	g++ main.cpp -o main
clean:
	rm -f *.o main
