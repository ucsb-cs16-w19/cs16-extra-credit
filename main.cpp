#include <iostream>
using namespace std;

/*=============================================================================
 |     Author:    Jonathan Sun
 |   To Compile:  Just type make
 |
 |        Class:  CS 16 Extra Credit Assignment
 |    Concepts:   For loops, If statements, Pass by pointer, Arrays, Functions
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  I will be taking linear algebra next quarter, so I thought it would be cool to code Gaussian Elimination to solve augmented matrcies.
 |
 |        Input:  The input is the number of rows your matrix will have, creating an n x n+1 matrix. You then input the values of each element in the matrix. There will be instrcutions printed during runtime to help explain this better.
 |
 |       Output:  This function solves a system of linear equations by back substitution. There can also be answers that contain "free variables"
 |
 |    Algorithm:  First input the information. rowSwap is called, which swaps the current row with another if the pivot value is 0. Then rowEchelonForm is called, which simplifies the matrix down to form an "upper right hand triangle." This loops over until the triangle is complete. Finally backSubstitution is called to solve for the variables in the system of linear equations.
 |
 |   Known Bugs:  The answers are sometimes off because of rounding issues and I left it because I think I spent too much time on this and that I should go study for the final instead.
 |
 *===========================================================================*/
void swapRow(double *matrix, int pivot, int rows, int columns);

void rowEchelonForm(double *matrix, int pivot, int rows, int columns);

void backSubstitution(double *matrix, int pivot, int rows, int columns);

int main() {

//asks for user input

	int n = 0;
	cout << "Enter number of rows in augmented matrix" << endl;
	cin >> n;
	cout << endl;

//creates 1 huge block of memory (array)

	cout << "You may visualize your augmented matrix by spacing/tabbing for elements in a" << endl;
	cout << "row and pressing Enter for new equation" << endl;
	int rows = n;
	int columns = n+1;
	double *matrix = new double[rows * columns];
	for(int i=0; i<rows*columns; i++) {
		cin >> *(matrix + i);
	}
	cout << endl;

//turns 1 line of array into 2D array

	cout << "This is your augmented matrix" << endl;
	for(int i=0; i<rows; i++) {
		for(int j=0; j<columns; j++) {
			cout << matrix[i*columns + j] <<  " ";
		}
		cout << endl;
	}
	cout << endl;

//begins Gaussian Elimination

	int pivot = 0;
	for(int i=0; i<rows-1; i++) {
		swapRow(matrix, pivot, rows, columns);
		rowEchelonForm(matrix, pivot, rows, columns);
		pivot++;
	}
	backSubstitution(matrix, pivot, rows, columns);
}


//checks if row needs swapping
void swapRow(double *matrix, int pivot, int rows, int columns) {
	double temp[columns - pivot];
	if(matrix[pivot*columns+pivot] == 0) {
		for(int i=pivot; i<rows; i++) {
			if(matrix[i*columns+pivot] != 0) {
				for(int j=0; j<columns; j++) {
					temp[j] = *(matrix+(i*columns+j));
					matrix[i*columns+j] = matrix[pivot*columns+j];
					matrix[pivot*columns+j] = temp[j];
				}
			}
		}
	}
}

//forms upper right triangle for back substitution
void rowEchelonForm(double *matrix, int pivot, int rows, int columns) {
	if(matrix[pivot*columns+pivot] < 0) {
		for(int i=0; i<columns; i++) {
			matrix[pivot*columns+i] *= -1;
		}
	}

	double multiplier = 0;
	cout << "Old Multiplier: " << multiplier << endl;
	cout << matrix[pivot*columns+pivot] << endl;
		multiplier = matrix[pivot*columns+pivot];
		cout << "Multiplier: " << multiplier << endl;
		for(int i=0; i<columns; i++) {
			matrix[pivot*columns+i] /= multiplier;
	}

	double temp[columns-pivot];
	for(int i=pivot+1; i<rows; i++) {
		if(matrix[i*columns+pivot] != 0) {
			if(matrix[i*columns+pivot] > 0) {
				for(int k=0; k<columns; k++) {
					matrix[i*columns+k] *= -1;
				}
			}
			int multiplier = -matrix[i*columns+pivot];
			for(int q=0; q<columns-pivot; q++) {
				temp[q] = multiplier * matrix[pivot*columns+pivot+q];
				matrix[i*columns+q+pivot] += temp[q];
			}
		}
	}
}

//solves the linear system
void backSubstitution(double *matrix, int pivot, int rows, int columns) {
	double answer[rows];
	for(int i=0; i<rows; i++) {
		answer[i] = 0;
	}
	answer[rows-1] = matrix[pivot*columns+pivot+1] / matrix[pivot*columns+pivot];
	pivot--;
	for(int i=rows-2; i>=0; i--) {
		for(int j=0; j<columns-1; j++) {
			answer[i] = answer[i] + matrix[i*columns+j]*answer[j];
		}
		answer[i] = matrix[(i+1)*columns-1] - answer[i];
	}
	for(int i=0; i<rows; i++) {
		cout << "x" << i+1 << ": " << answer[i] << endl;
	}
}
