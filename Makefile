CXX = g++

CXXFLAGS = -Wall -Wno-uninitialized

COMMON_OBJECT_FILES = checklistfuncs.o

main: main.o ${COMMON_OBJECT_FILES}
	${CXX} ${CXXFLAGS} ${LDFLAGS} $^ -o $@
clean:
	rm -f *.o main
