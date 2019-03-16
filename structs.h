#include <string>

using namespace std;

struct thingtodo{
	string name;
	string date;
	bool finished;
	thingtodo* next;
};

struct checklist{
	thingtodo* first;
	thingtodo* last;
};

