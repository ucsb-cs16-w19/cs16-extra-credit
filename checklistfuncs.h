#include "structs.h"
#include<string>

checklist* createchecklist();

void addtochecklist(checklist* checklist,string name, string date);

void printchecklist(checklist* checklist);

void checkoff(checklist* checklist,string eventname);

void deletecheckedoffitems(checklist* checklist);

void deleteitem(checklist* checklist, string eventname);

void deletechecklist(checklist* &checklist);
