# CS 16 Extra Credit Project
Extra credit project that showcases the concepts learned in CS 16.

To submit your project:
* Fork this repo
* Clone *your fork* of this repo
* Make your changes in that repo
* Commit your changes
* Push your changes (to the forked repo that you cloned above)

Whenever you are ready to submit your extra credit, submit a pull request through the GitHub.com interface.

Make sure that you update the documentation inside `main.cpp`. If you have more than one file to submit,
make sure that each file uses the same format and provides that documentation. Additionally, if you have
several files, ensure that your Makefile allows us to properly compile each project.

In this repo I have made a structure type and functions in order to make
an effective and useful to do list. I did this because I am one of those
people that love todo list and love checking things off a list, so I 
thought it would be fun to create a structure wiht linked lists and pointer
in order to complete this task.

There is a "node" called thingtodo which includes a string which is
the name of the thing todo, a string which should have the date
as to when it should be completed by, and a boolean which says whether or
not it is done.

There is also a struct called checklist which just has two pointers to the
first thingtodo, and the last thing todo.

There are a total of 7 functions

The first function is to create a checklist and does so by returning a 
pointer to a checklist created in the heap

The second function takes in an input of a pointer to a checklist, the 
name of the event of type string, and the date as to when it should be done
by. The finished part of thingtodo is assumed to be false. This new event
is added to the end of the todo list.

The third function just takes in a linked list and prints out the contents

The fourth function takes an input of a checklist, and a string of an
event name. It then changes the finihsed part of the thingtodo to true,which
causes the print function to print an x in front of the event, which
shows its checked off.

the fifth function takes in a checklist and loops through and checks
whether or not each events finished part is true. If it is it deletes
the event

the sixth function takes in a checklist and a string of the event name.
it loops through the todo list and deletes the event that is stated

the last function just delets the checklist as a whole and frees up memory.
