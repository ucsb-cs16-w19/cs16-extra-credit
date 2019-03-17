/*=============================================================================
 |     Author:    Aidan Jensen
 |   To Compile:  g++ main.cpp 
 |
 |        Class:  CS16
 |          
 |    Concepts:   Loops, flow control, VECTOR
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  This program is designed to test all the prime numbers up to an input limit for primeness
 |      SOLVE.
 |
 |        Input:  A limit: The upper bound of the numbers that you wish to test for primeness
 |
 |       Output:  A stream of text printed to the stream indicating if a number is prime, and if not, what division proves that it is not prime.
 |			ALSO, after testing to the upper limit, a prompt will ask you if you would like to return the contents of the prime_list vector
 |			effectively printing all primes before the input limit
 |
 |    Algorithm: This progam creates a vector intended to be filled with all of the prime numbers from 2 to the input limit
 |			It then tests a new number with all elements of the prime_list vector which are less than half of the number tested
 |			The number is returned as a prime if and only if
 |			(I)number%prime_list != 0
 |			(II) (number/2)< prime_list[i+i]
 |	
 |		
 |   Known Bugs:  No known bugs
 |      
 |
 *===========================================================================*/

#include<iostream>
#include <vector>
using namespace std;
//This is allprimes mk(III) using vectors
//This tests numbers up to 100,000 for primeness in approximately 10.5 seconds
//It tests numbers up to 500,000 in approximately 93
//This confuses me... in this case their are fewer mathematical operations taking place
//Why then would it be slower than the mkII code?
//Well at least this one preserves the prime list 
int main()
{
	long long int limit = -1;
	long long int number = 4;
	char print_primes = 0;
	vector <int> prime_list;
	prime_list.push_back(2);
	prime_list.push_back(3);
	do{	
	cout<<"Please input a number greater than 3 \nThis program will test all numbers until your input and determine \n whether or not they are prime";
	cout<< "\n Limit: "; cin>>limit;
	}
	while(limit<=3);



	for(number; number <= limit;number++)
		{	
	
			for(int i =0;(number/2)>= prime_list[i]; i++)
			{
				if(number%prime_list[i] != 0){
					if(prime_list[i+1]>number/2)
					{
						prime_list.push_back(number);
						cout<<endl<<"~~~~~~~~~~ "<< number << " IS a Prime Number!!! ~~~~~~~~~~"<<endl<<endl;
					}
					else
						continue;
				}
				else
					{	cout<<number<< " is NOT a Prime Number."<<endl;
						cout<< number << " can be divided by " <<prime_list[i] << " " << number/prime_list[i] << " times!" <<endl;
						break;
					}	
			}
		}
	cout<<"The input limit has been reached."<<endl;
	cout<<"Would you like to output the list of all prime numbers less than the input limit?"<<endl;
	cout<<"Input 1 and press enter to print the list... OR"<<endl;
	cout<<"Press any other key and press enter to terminate the program"<<endl;
	cin>>print_primes;
	
	int j =0;
	if(print_primes == '1')
	{for(int i = 0; i < prime_list.size(); i++)
		{cout<<prime_list[i]<<",   ";
			j++;
			if(j == 5){
				cout<<" "<<endl;
				j = 0;
			}
		}
	}
	else
		cout<<"Goodbye! :-)"<<endl;

}	


