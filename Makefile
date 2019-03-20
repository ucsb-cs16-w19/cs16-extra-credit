CXX = g++
# CXX = clang++

CXXFLAGS= -Wall -Wno-uninitialized

BINARIES=FuncsTest main

COMMON_OBJECTS=Funcs.o

all: ${BINARIES}

Iliad: ${BINARIES}
	./main

tests: ${BINARIES}
	./FuncsTest

FuncsTest: FuncsTest.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

main: main.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@


clean:
	/bin/rm -f ${BINARIES} *.o
