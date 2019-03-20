#include <iostream>
#include<string>
using namespace std;

/*=============================================================================
 |     Author:    Haotian Xia
 |   To Compile:  g++ -o main main.cpp
 |
 |        Class:  3:30pm
 |    
 |    Concepts:   struct loop linkedlist pointer switch
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  This is a program which help people to check the volleyball team historical record in three years and the best player in the team by using team number or team name.
 |      
 |
 |        Input:  team number or team name. each of the imformation works.
 |
 |       Output:  The historical record in three years, team name, team number,  and the best player's name. 
 |
 |    Algorithm:  To creat struct which include all information. using siwtch statement that allow people to search the imformation by team name or number. Using pointers to access the struct. 
 |      
 |
 |   Known Bugs:  In the first while loop, I want to break the program when i input the number which not exist. Right now, I can only stop the whole program after i input non-exist  number which means I can not continue to search other data. I want the result of the first while loop is same as the second while loop result.
 |
 |
 *===========================================================================*/

struct 	team{
	string name;//volleyball team name
	int number;//team number
	string region;//team region;
	int three;//result in three years ago 
	int two;//reusult in two years ago
	int last;//result in last year
	string player;//player name
	double  possibillity;// the percent of wining the medal in this year.
	team *next;
	};
int main () {
	team * ptr;
	team a;
	ptr = &a;
	a.name="China";
	a.number=1;
	a.region="Asian";
	a.three=12;
	a.two=7;
	a.last=13;
	a.player="Jiang Chuan";
	a.possibillity=15;
	team b;
	a.next=&b;
	b.name="USA";
	b.number=2;
	b.region="North America";
	b.three=3;
	b.two=1;
	b.last=4;
	b.player="Talor Sander";
	b.possibillity=98;
	b.next=NULL;
	cout<< "Team Name: "<<ptr->name<<endl;
	cout<< "Team region: "<<ptr->region<<endl;
	cout<< "Team Number: "<<ptr->number<<endl;
	cout<< "Team record in Last three years: "<<ptr->three<<", "<<ptr->two<<", "<<ptr->last<<endl;
	cout<< "Star Player: "<<ptr->player<<endl;
	cout<< "get medal chances percent: "<<ptr->possibillity<<"%"<<endl;
	cout<< "Team Name: "<<ptr->next->name<<endl;
	cout<< "Team region: "<<ptr->next->region<<endl;
        cout<< "Team Number: "<<ptr->next->number<<endl;
	cout<< "Team record in Last three years: "<<ptr->next->three<<", "<<ptr->next->two<<", "<<ptr->next->last<<endl;
	cout<< "Star Player:"<<ptr->next->player<<endl;
	cout<< "get medal chances percent:"<<ptr->next->possibillity<<"%"<<endl;
int q;//cin the team number;
cout<<"Please input searching method: 1.Team Number 2.Team Name"<<endl;
cin>>q;
if(q==1){
	while(1){
		int j;
		cout<< "Please input Team's Number: "<<endl;
		cin>>j;
		switch(j){
			case 1:
				cout<< "Team Name: "<<ptr->name<<endl;
				cout<< "Team region: "<<ptr->region<<endl;
				cout<< "Team Number: "<<ptr->number<<endl;
				cout<< "Team record in Last three years: "<<ptr->three<<", "<<ptr->two<<", "<<ptr->last<<endl;
				cout<< "Star Player: "<<ptr->player<<endl;
				cout<< "get medal chances percent: "<<ptr->possibillity<<"%"<<endl;
				break;
			case 2:
				 cout<< "Team Name: "<<ptr->next->name<<endl;
				 cout<< "Team region: "<<ptr->next->region<<endl;
				 cout<< "Team Number: "<<ptr->next->number<<endl;
				 cout<< "Team record in Last three years: "<<ptr->next->three<<", "<<ptr->next->two<<", "<<ptr->next->last<<endl;
				 cout<< "Star Player: "<<ptr->next->player<<endl;
				 cout<< "get medal chances percent: "<<ptr->next->possibillity<<"%"<<endl;

				 break;
		}
		break;
	}
}
else{
	while(1){
		cout<<"Please input the Team's Name: "<<endl;
		string n;
		cin>>n;
		if (n==a.name){ 
			cout<< "Team Name: "<<ptr->name<<endl;
			cout<< "Team region: "<<ptr->region<<endl;
			cout<< "Team Number: "<<ptr->number<<endl;
			cout<< "Team record in Last three years: "<<ptr->three<<", "<<ptr->two<<", "<<ptr->last<<endl;
			cout<< "Star Player: "<<ptr->player<<endl;
			cout<< "get medal chances percent: "<<ptr->possibillity<<"%"<<endl;
		}
		else if (n==b.name){
			cout<< "Team Name: "<<ptr->next->name<<endl;
			cout<< "Team region: "<<ptr->next->region<<endl;
			cout<< "Team Number: "<<ptr->next->number<<endl;
			cout<< "Team record in Last three years: "<<ptr->next->three<<", "<<ptr->next->two<<", "<<ptr->next->last<<endl;
			cout<< "Star Player: "<<ptr->next->player<<endl;
			cout<< "get medal chances percent: "<<ptr->next->possibillity<<"%"<<endl;
	}
		else{break;
		}
	}
}
exit(1);					
}
