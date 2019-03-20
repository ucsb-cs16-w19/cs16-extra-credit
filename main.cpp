#include <iostream>
using namespace std;

/*=============================================================================
 |     Author:    STUDENT'S NAME HERE
 |   To Compile:  EXPLAIN HOW TO COMPILE THIS PROGRAM
 |
 |        Class:  NAME AND TITLE OF THE CLASS FOR WHICH THIS PROGRAM WAS
 |                      WRITTEN
 |    Concepts:   DESCRIBE THE CONCEPTS FROM THE COURSE THAT THIS PROGRAM USES
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  DESCRIBE THE PROBLEM THAT THIS PROGRAM WAS WRITTEN TO
 |      SOLVE.
 |
 |        Input:  DESCRIBE THE INPUT THAT THE PROGRAM REQUIRES.
 |
 |       Output:  DESCRIBE THE OUTPUT THAT THE PROGRAM PRODUCES.
 |
 |    Algorithm:  OUTLINE THE APPROACH USED BY THE PROGRAM TO SOLVE THE
 |      PROBLEM.
 |
 |   Known Bugs:  IF THE PROGRAM DOES NOT FUNCTION CORRECTLY IN SOME
 |      SITUATIONS, DESCRIBE THE SITUATIONS AND PROBLEMS HERE.
 |
 *===========================================================================*/
void swapRow(double *matrix, int pivot, int counter, int rows, int columns);

int main() {

//asks for user input

	int n = 0;
	cout << "Enter number of rows in augmented matrix" << endl;
	cin >> n;
	cout << endl;

//creates 1 huge block of memory

	cout << "You may visualize your augmented matrix by spacing/tabbing for elements in a" << endl;
	cout << "row and pressing Enter for new equation" << endl;
	int rows = n;
	int columns = n+1;
	double *matrix = new double[rows * columns];
	for(int i=0; i<rows*columns; i++) {
		cin >> *(matrix + i);
	}

//turns 1 line of array into 2D array

	cout << "This is your augmented matrix" << endl;
	for(int i=0; i<rows; i++) {
		for(int j=0; j<columns; j++) {
			cout << matrix[i*columns + j] <<  " ";
		}
		cout << endl;
	}
	int pivot = 0;
	int counter = 1;
	cout << "Matrix 1" << endl;
	swapRow(matrix, pivot, counter, rows, columns);
	pivot++;
	counter++;
	cout << "Matrix 2" << endl;
	swapRow(matrix, pivot, counter, rows, columns);
	/*
	cout << "New Matrix" << endl;
	for(int i=0; i<rows; i++) {
		for(int j=0; j<columns; j++) {
			cout << matrix[i*columns + j] << " ";
		}
		cout << endl;
	}
	*/
}

//time for Gaussian Elimination

//checks if row 1 needs swapping
void swapRow(double *matrix, int pivot, int counter, int rows, int columns) {
	double temp[columns - pivot];
	if(matrix[pivot*columns+pivot] == 0) {
		for(int i=pivot; i<rows; i++) {
			if(matrix[i*columns+pivot] != 0) {
				for(int j=0; j<columns-pivot; j++) {
					temp[j] = *(matrix+(i*columns+pivot));
					matrix[i*columns+pivot] = matrix[j];
					matrix[j] = temp[j];
				}
			}
		}
	}


	//new matrix
	cout << "Performed row swap" << endl;
	for(int i=0; i<rows; i++) {
		for(int j=0; j<columns; j++) {
			cout << matrix[i*columns + j] << " ";
		}
		cout << endl;
	}
}
