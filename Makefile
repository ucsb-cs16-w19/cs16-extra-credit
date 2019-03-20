main: main.o
	g++ main.cpp -o main
	./main
clean:
	rm -f *.o main
