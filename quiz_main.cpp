// quiz.cpp
// enter a file, it quizzes you on it
// file specifications: word, then definition, separated by ":"

#include <iostream>	// for cout
#include <cstdlib>	// for exit(1)
#include <fstream>	// for reading files
#include <string>	// for reading strings
using namespace std;

int main(int argc, char *argv[]) {

	// if not 1 argument, error message + usage
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " filename\n\n"
		<< "File specifications:\n\t- list of words and defenitions\n\t"
		<< "- separted by colon and space, each on new line\n\n"
		<< "Example:\n\tword_1: defenition_1\n\t...\n\tword_n: defenition_n\n\n";
		exit(1);
	}

	// variable declarations
	ifstream file;
	string quiz_file = argv[1];

	string definition = "empty_def";
	string word = "empty_word";
	string guess = "empty_guess";	

	string continue_quiz;
	int wrong = 0;
	int question_num = 1;

	file.open(quiz_file);
	if (file.fail()) {
		cerr << "File invalid\n";
		exit(0);
	}

	
	cout << "\n-----------------------------------------------------------\n";
	cout << "welcome to the mathew quiz \ni will now quiz u on the words\n";
	cout << "type Ctrl + c to quit\n";
	cout << "-----------------------------------------------------------\n\n";


	for (word; getline(file, word, ':'); ) {
		getline(file, definition, '\n');

		definition = definition.erase(0,1);
		
		cout << question_num << ". what is: " << definition << endl << endl;
		cout << ">> ";
		getline(cin, guess);
		
		if (guess == word)
			cout << "\n    good job\n";
		else {
			cout << "\n    wrong, bitch. thats minus 1 point\n";
			cout << "    answer = " << word << endl;
			wrong += 1;
		}

		cout << "    continue? (y/n) ";
		getline(cin, continue_quiz);
		if (continue_quiz == "n") {
			question_num +=1;
			break;
		}

		question_num +=1;

		cout << "\n------------------------------------------------------------\n";
	}

	
	if (continue_quiz == "n")
		cout << "\n------------------------------------------------------------\n";

	float percent = (((question_num - 1 - wrong)*1.0)/((question_num - 1)*1.0))*100; 

	cout << "results: you got a " << percent << "% on this quiz\n\n";

	return 0;
}
