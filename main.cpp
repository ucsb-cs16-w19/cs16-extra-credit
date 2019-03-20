#include <iostream>
#include <string>
using namespace std;

/*=============================================================================
 |     Author:    Kristy Lu
 |   To Compile:  Type "g++ -o main main.cpp" to compile and run program
 |
 |        Class:  Computer Science 16
 |                      
 |    Concepts:   If-else statements, initialization, user input, void functions, C++ operators, 
 |		function implementation	
 +-----------------------------------------------------------------------------
 |
 |  Description:  This program is designed to calculate tips for meals with preferred 
 |      		percentages and unique party amounts.
 |
 |        Input: Bill amount, party amount, desired tip percentage 
 |
 |       Output: Total bill amount, tip amount, tip per person, and  
 |		 total per person
 | 
 |    Algorithm: The program asks for user input of the bill, desired tip amount, and amount 
		 of people in the party. Creating a tip function, it calculates the desired
		 results using arithmetic. The program also asks the user if they wish to recalculate,
		 perhaps with a different tip percentage.


 |
 |   Known Bugs:  THe program only asks if the user wishes to recalculate once. 
 |      
 |
 *===========================================================================*/
void Tip(double total){

	double percentage = 0;
	double tip = 0;
	int party = 0;
	double tip_per_person = 0;
	double total_per_person = 0;
	cout << "Enter amount of people in your party: " <<endl;
	cin >> party;
	cout << "Enter desired tip percentage (integer): " <<endl;
    	cin >> percentage;
	
	if(percentage <= 0){
		cout << "Invalid tip percentage" << endl;
		cout << "Enter desired tip percentage: " << endl;
		cin >> percentage; 
	}
	
	percentage = percentage/100;	
	tip = total * percentage;
	total = total + tip;
	tip_per_person = tip/party;
	total_per_person = total/party;

	cout << "Total Bill Amount:    "<< total<< endl;
	cout << "Total Tip Amount:     "<< tip << endl;
	cout << "Total Tip per person: "<< tip_per_person<<endl;
	cout << "Total per person:     "<< total_per_person<<endl;
}

int main () {
	double total = 0;
	string response = "";
	cout << "***Welcome to your Tip Calculator!***" << endl;
	cout << "Enter Bill Amount: " << endl;
	cin >> total;
	Tip(total);

	cout << "Do you want to recalculate? Y/N" <<endl;
	cin >> response;

	if(response == "Y" || response == "y"){
		cout << "Enter Bill Amount: ";
		cin >> total;
		Tip(total);
	}
	else if(response == "N" || response == "n"){
		cout <<"Thank you for using the Tip Calculator!"<< endl;
		return 0;
	}
	


}
