#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;
/*====================================================================================================
 |     Author:    Ronak Parikh
 |   To Compile:  Either run  g++ main.cpp -o main or run make
 |
 |        Class:  Computer Science 16: Problem Solving with Computers I for Final Extra Credit Proudct
 |    Concepts:   My Program uses many Flow Control statements, algorithms, arrays, and passing arrays to functions. 
 |
 +----------------------------------------------------------------------------------------------------
 |
 |  Description:  1-Variable Statistics Calculator from an array (Mean, Median, Mode, and Standard Deviation) 
 |
 |        Input:  Must input an array of float 10
 |
 |       Output:  Outputs Mean, Median, Mode and Standard Deviation. 
 |
 |    Algorithm:  Defined seperate functions to find each. 
 |                Mean: Simple accumulator function adding each value of the array to the a total value. 
 |                Median: First used the sort function to list the elements of the array from smallest to largest. Then made two cases.
 |                        Case(1): If the array is even, then it divides both the middle values added together by 2.
 |                        Case(2): If the array is odd, then it find the [size/2]th element and returns it.
 |                        Note: Because we have an array of size 10, the function will always be the first case. I programmed the second case if the programmer ever changed the array size.
 |                Mode: First, the program iterates through the array for when it is one less than the size of the array. In our case this is 0 to 9. Then, it checks if the first and second
 |                      value are identifical. If they are, the functions add 1 to the count. We then set the max value to that count so we can see which is the largest value.
 |                Standard Deviation: First I used the Mean value from above and then iterated through another loop to keep adding each terms standard deviation sDev += pow(data[x] - mean, 2);
 |   
 |     Known Bugs:  No bugs in particular but when there are multiples modes, the mode function is designed to take the closest mode to the beginning of the list rather than listing both modes. 
 |
 *===================================================================================================*/

//declaring array of floats of a int size so we can calculate statistics 
float calcMean(float data[]);
float calcMedian(float data[]);
float calcMode(float data[]);
float calcSTD(float data[]);

float sum = 0.0; 

int main(int argc, char *argv[]) {
	if (argc!= 11) {
		// if the user does not give 10 inputs, we will return an error
		cerr << "Usage: " << argv[0] << " Not 10 terms" << endl;
		exit(1); 
	}
	int n = 0;
	// creates the array
	int size = 10;
	float data[10];
	for(int n; n < 10; n++) {
		data[n] = stoi(argv[n+1]);
	}

	// allows the user to input size of array
	// puts each value into the array of choosen size
	cout << "Statistics Report: " << endl;
	cout << "Mean = " << calcMean(data) << endl; 
	cout << "Median = " << calcMedian(data) << endl;
	cout << "Mode = " << calcMode(data) << endl; 
	cout << "Standard Deviation = " << calcSTD(data) << endl;
	return 0;
}

float calcMean(float data[])
{
	int size = 10; 
	float total = 0;
	float mean = 0;
	for(int i = 0; i < size; i++) {
		total += data[i];
	}
	mean = total/size;
	cout << mean << total << size;
	return mean;
}

float calcMode(float data[]) {
	int size = 10;
	float count = 1;
        float max = 0;
        float mode = data[0];

        for (int i = 0; i < size - 1; i++)
        {
           if (data[i] == data[i+1]) //check if first value is same next
           {
              count++;
	   }
           if (count > max) //creates new max
           {
                  max = count;
                  mode = data[i];
           }
           else {
              count = 1; //reset
           }
	}
	return mode; 
}

float calcMedian(float data[])
{
	int size = 10; 
	//Must sort the array first
	sort(data, data+size);
	//if size is even

	if (size % 2 == 0) {
		return double(data[(size-1)/2]+data[size/2])/2.0;
	}
	//else the size is odd
	else {
		return double(data[size/2]);
	}
}

float calcSTD(float data[])
{
	int size = 10; 
	float total = 0;
	float mean = 0;
	float sDev = 0;
	for(int i = 0; i < size; i++) {
		total += data[i];
	}
	mean = total/size;
	for(int x = 0; x < size; x++)
	{
        	sDev += pow(data[x] - mean, 2);
	}
	return sqrt(sDev / size);
}
