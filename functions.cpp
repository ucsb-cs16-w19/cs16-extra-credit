// Mathew Kramsch
// functions.cpp
// function definitions for functons used in main.cpp 

#include <iostream>	// for cout
#include <fstream>	// for reading files
#include <cstdlib>
#include <string>
using namespace std;


// Postcondition: prints a line
void printline() {
	cout << "\n------------------------------------------------------------\n";
	return;
}



// Precondition: quiz_file is the name of a .txt file
// Postcondition: prints a message that indicates the start
		// of the quiz
void start_message(string quiz_file) {
	
	// make a new variable and store file's name in it
	// and erase the .txt extension
	string quiz_name = quiz_file;
	quiz_name = quiz_name.substr(0, (quiz_name.length() - 4));
	quiz_name[0] = toupper(quiz_name[0]);

	printline();	
	cout << " " << quiz_name << " Quiz:\n Enter the correct term for the definition.";
	printline();
	cout << endl;	
	return;
}



// Precondition: q_nun is the question number, num_wrong is the number
		// of incorrect answers the user has given so far, term is 
		// the key word in the file, and definition is the term's 
		// definition, specified in the file. cont is a string that 
		// is equal to "n" if the user does not wish to continue or "y"
// Postcondition: prints the definition and prompts the user for input
		// if the user's input matches the term, prints a message indicating
		// that the guess was correct, and vice versa if incorrect.
void quiz_term(int q_num, int &num_wrong, string term, string def, string &cont) {
	
	// variable to hold user's guess of the term for the definition
	string guess = "empty_guess";

	// print the definition, and ask the user for the term
	cout << q_num << ". What is: " << def << endl << endl;
	cout << ">> ";
	getline(cin, guess);
	
	// if their guess matches the correct term
	if (guess == term)
		cout << "\n    Correct. Congratulations.\n";

	// if they guessed wrong
	else {
		cout << "\n    Wrong, stupid. You should know this. C'mon.\n";
		cout << "    Answer = " << term << endl;

		// add 1 to the var that keeps track of how much they got wrong
		// the score at the end is calculated using this
		num_wrong ++;
	}

	// ask if user wants to continue to the next question
	cout << "    Continue? (y/n) ";
	getline(cin, cont);
	return;
}




// Precondition: ifstream_file is attatched to a text file with words and definitions
		// seperated by a colon (ie, ':')
// Postcondition: quizes the user on each term on each line of the file
		// returns the percent of questions the user answered correctly
void quiz_function(ifstream &ifstream_file) {

	// variable declarations:
	string definition = "empty_def";	// definition of word
	string word = "empty_word";			// the key term
	string continue_quiz= "";			// user's answer to (y/n) continue the quiz
	int wrong = 0;						// number of incorrect questions
	int question_num = 1;				// variable to keep track of question number

	// go through each line in the file
	// for each line, store everything up to the ':' character
	// in the string word
	for (word; getline(ifstream_file, word, ':'); ) {	
		
		// store the rest of the line after word in the string definition
		getline(ifstream_file, definition, '\n');
		definition = definition.erase(0,1);		// erase the colon
		
		quiz_term(question_num, wrong, word, definition, continue_quiz);
	
		// if they don't want to continue, break out of for loop
		if (continue_quiz == "n") {
		// add 1 to question_num, so score is calculated correctly
			question_num +=1;
			break;
		}

		// increase the question number by one
		question_num ++;
		printline();
	}

	
	// print a line if they terminated the quiz early 
	// to make formatting nicer
	if (continue_quiz == "n")
		printline();

	// calculate score of quiz
	float percent = (((question_num - 1 - wrong)*1.0)/((question_num - 1)*1.0))*100; 

	// print what percent of the questions the user answered correctly
	cout << "Results: you got a " << percent << "% on this quiz\n\n";
	return;
}
