#include <iostream>
#include <string>
using namespace std;

/*=============================================================================
 |     Author:    Zhenni Xu
 |   To Compile:  To compile this program, you just need to follow the instruction
 |                it is given.
 |                
 |
 |        Class:  CS 16
 |           
 |    Concepts:   This program is designed for administrator in the University for
 |                adding students who apply for scholarship to the waitlist and 
 |                print out the final result if the administrator wants to
 |                check . Meanwhile, it would automatically delete the students
 |                who doesn't match the requirements set by the university.
 |                Eventually, after providing password, the system can 
 |                add different amounts of scholarship to students who meet the
 |                requirments but in different status of GPA.
 +-----------------------------------------------------------------------------
 |
 |  Description:  This program solves the hardship of collecting the information
 |                of students who applied for scholarship. It also designed for
 |                automatically selecting students who meet the requirment of
 |                scholarship.
 |
 |        Input:  The User input the information of each student who want to 
 |                apply for scholarship (The information includes a student's
 |                name, GPA, current amount of scholarship, status 
 |                citizen/non-citizen.)
 |              
 |       Output:  It should remain and present the information for students who 
 |                meet the requirement on the waitlist with their current 
 |                amount of scholarship.
 |
 |    Algorithm:  Struct, List, Pointer, If-statement, Switch, and other basic
 |                application of C++ language. 
 |
 |   Known Bugs:  When the system asks for " Enter the student information for
 |                adding students to the waitlist ," do not press characters 
 |                other than 1,2,3, and 4. Please follow the instruction as
 |                the system said. Meanwhile, for Final step 3), it requires a
 |                password 201903 for adding scholarship for all the students.
 |                The user can only use Final step for once or else it would 
 |                continually adding scholarship if the user requests it again
 |                and again, and that is why there's a password setting for
 |                enter the Final step 3). 
 *===========================================================================*/
struct Student {
	string name;
	double GPA;
	double scholarship;
	string status;
	Student* next;
};

struct Waitlist {
	Student* first;
	Student* last;
};

void addToWaitList( Waitlist* &system, Student* n1);
void formalList(Student* &first, double con1, string con2);
void addScholarship(Student* &first, double mark1, double mark2);
int main() {
   Waitlist* UCSB = new Waitlist;
   int x = 0;
   while(x!=5)
 {
   cout <<" Welcome to UCSB Student Scholarship system " <<endl;
   cout <<"------------------------------------------- " <<endl;
   cout <<"Enter the student information for adding students to the waitlist:"<<endl;
   cout<<"Add Student Information: (1)"<<"                   "
       <<"Check the current formalList after test: (2)"<<"   "
       <<"Final Step for Adding Scholarship to barc: (3)"<<endl
       <<"Quit: (4)" <<endl;
   int x;
   cin >> x;
   cout << endl;
   switch(x)
   {
	   case 1:
		   {Student* s = new Student;
	            cout<<"Please enter the Name:"<<endl;
		    cin>> s -> name;
		    cout<<"Please enter the GPA:"<<endl;
		    cin>> s -> GPA;
		    cout<<"Please enter the amount of scholarship"
			<<"in his/her account:" <<endl;
		    cin>> s ->scholarship;
	 cout<<"Pleace enter the status(citizen/non-citizen):"<<endl;
	 cin>> s -> status;
	 s -> next = NULL;
	 addToWaitList(UCSB,s);
	            break;
		   }
	    case 2:
		   { formalList((UCSB -> first), 2.5, "citizen");
		        for(Student* t = UCSB -> first; t -> next != NULL; t = t -> next){
			cout<<"Name: "<<(t -> name)<<" GPA: "<<(t -> GPA)<<" Amount of Scholarship: "<<(t -> scholarship)<<endl;
			cout<<"Status: "<<(t -> status) <<"   "<<endl;
			cout<<"------------------------------------------------------"<<endl;
			}
	            break;
		   }
	    case 3:
		   { int password;
	             cout<<"Warning: Do not execute this step for more than one time"<<endl;
		     cout<<"ENTER THE PASSWORD FOR CHANGING: "<<endl;
		     cin>> password;
		     if ( password == 201903 )
			{
			  addScholarship((UCSB -> first),3.0,3.5);
			 for(Student* t = UCSB -> first; t -> next != NULL; t = t -> next){
			 cout<<"Name: "<<(t -> name)<<" GPA: "<<(t -> GPA)<<" Current Amount of Scholarship: "<<(t -> scholarship)<<endl;
			 cout<<"Status: "<<(t -> status) <<"   "<<endl;
			 cout<<"------------------------------------------------------"<<endl;
			 }
			}else{
				cout<<"------Permission Denied------"<<endl;
			}
		     break;
		   }
	    case 4:
		   { cout << "------Bye-----"<<endl;
		     delete UCSB;
		     exit(1);
		     break;
		   }
   }
 }
   return 0;
}

void addToWaitList( Waitlist* &system, Student* n1)
{ if (system -> first == NULL)
    { n1 = system -> first;
      n1 = system -> last;
    }else{
      n1 = system -> last -> next;
      system -> last = n1;
 }
}
void formalList(Student* &first, double con1, string con2)
{ if (first == NULL)
	return;
  while(first != NULL && ((first -> GPA < con1)||(first -> status != con2))){
		  Student* temp = first;
		  first  = first -> next;
		  delete temp;
		  }
  if (first == NULL)
  return;

  Student* test = first;
  while(test -> next != NULL){
  if((test->next->GPA < con1)||(test->next->status != con2)){
  	Student* temp = test->next;
	test -> next = test -> next -> next;
	delete temp;
	}else {
	test = test -> next;
	}
	}
	}
void addScholarship(Student* &first, double mark1, double mark2)
{
  if (first == NULL)
  return;
  
  Student* test = first;
  while(test->next != NULL){
  if(test -> GPA < mark1){
  test->scholarship = test->scholarship + 1000;
  test = test -> next;
  }else if(test -> GPA < mark2){
  test->scholarship = test->scholarship + 2000;
  }else{
  test->scholarship = test->scholarship + 3000;
  }
  test = test -> next;
  }
  }
