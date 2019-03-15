/*=============================================================================
 |     Author:    Aidan Jensen
 |   To Compile:  g++ main.cpp 
 |
 |        Class:  CS16
 |          
 |    Concepts:   Loops, flow control
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  This program is designed to test all the prime numbers up to an input limit for primeness
 |      SOLVE.
 |
 |        Input:  A limit: The upper bound of the numbers that you wish to test for primeness
 |
 |       Output:  A stream of text printed to the stream indicating if a number is prime, and if not, what division proves that it is not prime
 |
 |    Algorithm: This program uses an approach of testing every division from i = 1 to sqrt(number) for all numbers <= limit
 |     		and returning that it is prime if and only if 
 |		(I)The modulo of number and i !=0	
 |		(II)i == sqrt(number)
 |   Known Bugs:  No known bugs
 |      
 |
 *===========================================================================*/

#include<iostream>
#include <cmath>
using namespace std;
//This is allprimes.cpp mk(II) It takes appx 5 seconds to test every number up to 100,000 for primeness
//It takes appx 28 seconds to test all numbers up to 500,000
//It is faster that the first model because it only tests divisions up to the sqrt rather than to half
int main()
{
	long long int limit = -1;
	long long int number = 3;
	do{	
	cout<<"Please input a number greater than 3 \nThis program will test all numbers until your input and determine \n whether or not they are prime";
	cout<< "\n Limit: "; cin>>limit;
	}
	while(limit<=3);

	for(number; number <= limit;number++)
		{	
			long long int divisions = sqrt(number);

			for(int i =2;i<= divisions; i++)
			{
				if(number%i != 0)
					if(i==divisions)
						cout<<endl<<"~~~~~~~~~~ "<< number << " IS a Prime Number!!! ~~~~~~~~~~"<<endl<<endl;
					else
						continue;
					else
					{	cout<<number<< " is NOT a Prime Number."<<endl;
						cout<< number << " can be divided by " << i << " " << number/i << " times!" <<endl;
						break;
					}	
			}
		}	
}	

