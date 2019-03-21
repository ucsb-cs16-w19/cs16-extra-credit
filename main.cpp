// Mathew Kramsch
// main.cpp
// main file for quiz program

#include <iostream> 	// for using cerr
#include <fstream> 		// for reading files
#include <string>
#include <cstdlib>
#include "functions.h"	// for using start_message() and quiz_function()
using namespace std;

/*=============================================================================
 |     Author:    Mathew Kramsch
 |   To Compile:  Run 'make quiz' 
 |
 |        Class:  CS16 
 |		
 |    Concepts:   This program uses file input and output, command line arguments,
 |				  dividing up a program into multiple files, header files, makefiles,
 | 				  flow control statements, string class functions, passing by 
 |				  reference in functions
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  This program allows the user quiz him/herself on a list of terms
 |				  and definitions to help with studying for an exam. It's like
 | 				  quizlet but a lot cooler because its in a terminal and you
 |				  don't need wifi. (I used this to study for my CLASS40 test)
 |
 |        Input:  The program requires a text file with extension .txt that 
 |				  contains words and definitions separated by a colon (ie. ':'). 
 |
 |       Output:  The program outputs a quiz of each term and definition that
 |				  outputs a definition and prompts the user to enter the corresponding
 | 				  term. At the end of the quiz, the percent of the questions 
 |			      answered correctly is reported
 |
 |    Algorithm:  First, the program opens the file. Then it reads each line of
 |				  the file until there are no more lines to read. In the variable,
 | 				  word, it stores the everything in the line until it hits a
 |				  colon. This should be the term. It then stores the rest of the
 | 				  line in the variable, definition, minus the colon. Using these
 | 				  variables (which are redefined for each line in the for loop),
 |				  the program quizes the user and prompts for input. If the user
 | 				  enters a guess exactly equal to the term on the file for the 
 |				  definition, the program prints a message that the answer was correct.
 |				  If the answers do not match, it prints a message that the answer
 |				  was incorrect, and adds one to a counter variable, wrong.
 |				  This variable, along with another variable that counts the number
 |				  of questions, is used to calculate the percentage score, which
 |				  is printed at the end of the quiz. The user also is able to exit
 |				  out of the quiz before the end because flow control statement
 |				  was added to break out of the for loop if the user answers 'n'
 | 				  to the 'continue?' question.
 |				
 |
 |   Known Bugs:  There are no bugs in the program if it is used correctly, 
 |				  ie. correct number of arguments, correct file type.
 |
 *===========================================================================*/

int main (int argc, char *argv[]) {

	// if not 1 argument, error message + usage
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " filename\n\n"
		<< "File specifications:\n\t- list of words and defenitions\n\t"
		<< "- separted by colon and space, each on new line\n\n"
		<< "Example:\n\tword_1: defenition_1\n\t...\n\tword_n: defenition_n\n\n";
		exit(1);
	}
	
	// variable declarations
	ifstream ifs;
	string quiz_file = argv[1];  

	// open the file
	ifs.open(quiz_file);	// sets value of variable ifs to the file name
	if (ifs.fail()) {			// prints an error message if can't open file
		cerr << "File invalid.\n";
		exit(1);
	}

	// display the starting message 
	start_message(quiz_file);

	// run the actual quiz	
	quiz_function(ifs);

    return 0;
}
