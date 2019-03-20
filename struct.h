#include <string>

struct Word{
	std::string value;
	int lineNum;
	Word *next;
};

struct History{
	Word *head;
	Word *tail;
};
