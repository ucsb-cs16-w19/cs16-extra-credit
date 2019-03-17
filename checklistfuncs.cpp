#include <string>
#include<iostream>

#include "structs.h"

using namespace std;
//preconditions: no input
//post conditions: returns a pointer to a new checklist
checklist* createchecklist(){
	checklist* newchecklist = new checklist;
	newchecklist->first = NULL;
	newchecklist->last = NULL;
	return newchecklist;
}

//preconditions: a pointer to a checklist, the name of the event
//you want to create of type string, and the date of type string.
//postconditions:adds a new thingtodo with the name, and date given
//to the end of the checklist inputted.
void addtochecklist(checklist* checklist,string name, string date){
	thingtodo* newevent = new thingtodo;
	newevent->name = name;
	newevent->date = date;
	newevent->finished = false;
	newevent->next = NULL;

	if (checklist->first == NULL){
		checklist->first = newevent;
		checklist->last = newevent;
		return;
	}

	else{
		checklist->last->next = newevent;
		checklist->last = newevent;
		return;
	}
}

//preconditions: pointer to a checklist
//postconditions: prints out the contents of the checklist
void printchecklist(checklist* checklist){
	if(checklist == NULL){
		cout<<"list not found"<<endl;
		return;
	}
	if(checklist->first==NULL){
		cout<<"list is empty"<<endl;
		return;
	}
	cout<<"Things to do: "<<endl;
	for(thingtodo* event = checklist->first; event != NULL; event = event->next){
		if(event->finished){
			cout<<"X "<<event->name<<" by "<<event->date<<endl;
			cout<<endl;
		}else{
			cout<< "- "<<event->name<<" by "<<event->date<<endl;
			cout<<endl;
		}
	}
	return;
}

//preconditons: pointer to a checklist, the event name of type string
//postconditions: when the checklist is printed, the event inputted
//will be checked off
void checkoff(checklist* checklist,string eventname){
	for(thingtodo* event = checklist->first; event!= NULL; event = event->next){
		if(event->name == eventname){
			event->finished = true;
		}
	}
	return;
}

//preconditions: pointer to a checklist
//postconditions: deletes all checked off items on the checklist
void deletecheckedoffitems(checklist* checklist){
	if(checklist->first == NULL){
		cout<<"checklist is empty"<<endl;
		return;
	}
	if(checklist->first->finished){
		thingtodo* discard = checklist->first;
		checklist->first = checklist->first->next;
		delete discard;
		return;
	}
	for(thingtodo* event = checklist->first; event!=NULL; event = event->next){
		if(event->finished){
			for(thingtodo* prev = checklist->first; prev != NULL; prev = prev->next){
				if(prev->next == event){
					prev->next = event->next;
					thingtodo* discard = event;
					event = prev;
					delete discard;
					return;
				}
			}
		}
	}
	cout<<"event not found in list"<<endl;
	return;
}

//preconditions: pointer to a checklist, and the event name that is to be
//deleted of type string
//postconditions: deletes the item off of the checklist
void deleteitem(checklist* checklist, string eventname){
	for(thingtodo* event = checklist->first; event != NULL; event = event->next){
		if(event->name == eventname){
			checkoff(checklist,eventname);
			deletecheckedoffitems(checklist);
			return;
		}
	}
	cout<<"event not found"<<endl;
	return;
}

//preconditions: pointer to a checklist
//postcondiitons: deletes the checklist and frees up memory
void deletechecklist(checklist* &checklist){
	thingtodo* event = checklist->first;
	while(event!=NULL){
		thingtodo* nextevent = event->next;
		delete event;
		event = nextevent;
	}
	delete checklist;
	checklist= NULL;
}
