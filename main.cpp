#include <iostream>
#include<string>
using namespace std;

/*=============================================================================
 |     Author:    Liang Li
 |   To Compile:  EXPLAIN HOW TO COMPILE THIS PROGRAM 
 |
 |        Class:  CS16 AND USING C++ ;But idea from CS8 python class
 |
 |    Concepts:  USER INPUT,VOID FUNCTION, INITIALIZATION,FUNCTION IMPLEMENTATION, IF-ELSE STATEMENT.
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  This program can tell customer how much tips they recommered to pay and we did the similar program from cs8. 
 |
 |        Input:  party size , tip percentage.
 |
 |       Output:  Customer bill amount and tips.
 |
 |    Algorithm: customer provide the percentage of tips and we print out the bill amount with tips.
 |      
 |
 |   Known Bugs: So far, it is good.If it has any problem please describel and comment below. 
 |
 *===========================================================================*/

void Tip(double bill){
    
    double percentage = 0;
    double tip =0;
    int party=0;
    double total_per_person=0;
    double tip_per_person=0;
    cout << "Enter how many people in your party:"<<endl;
    cin >>party;
    cout<<"Tell us what is the your tip perentage:"<<endl;
    cin>> percentage;

    if(percentage <=0){
       cout << "Invalid tip percentage" << endl;
		cout << "Enter correct tip percentage: " << endl;
		cin >> percentage;     
}
        percentage = percentage/100;	
	tip = bill * percentage;
	bill = bill + tip;
	tip_per_person = tip/party;
	total_per_person = bill/party;

	cout << "Total Bill Amount: "<< bill<< endl;
	cout << "Total Tip Amount: "<< tip << endl;
	cout << "Total Tip per person: "<< tip_per_person<<endl;
	cout << "Total per person:     "<< total_per_person<<endl;
}

int main () {
	double bill = 0;
	string response = "";
	cout << "Welcome to Tip Calculator!" << endl;
	cout << "Enter Bill Amount " << endl;
	cin >> bill;
	Tip(bill);
        // Try to ask custmoer do they need to change the tip percentage
	cout << "Do you want to recalculate? Y/N" <<endl;
	cin >> response;

	if(response == "Y" || response == "y"){
		cout << "Enter Bill Amount: ";
		cin >>bill;
		Tip(bill);
	}
	else if(response == "N" || response == "n"){
		cout <<"Thank you for using the Tip Calculator!"<< endl;
		return 0;
	}	

    return 0;
}
