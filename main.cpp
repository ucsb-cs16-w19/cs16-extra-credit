/*=============================================================================
 |     Author:    Daniel Wilson
 |   To Compile:  make main.cpp (default make) 
 |
 |        Class:  CS16
 |    Concepts:   While loops, functions, user input, user output
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  Sometimes people need a good game of hangman.
 |
 |        Input:  User inputs a letter, or enters ! to quit.
 |
 |       Output:  Program outputs hangman ASCII art.
 |
 |    Algorithm:  Program uses a while loop to run program.
 |
 |  Issues: Requires word be updated in the code manually. 
        (Sorry I didn't find time to implement promised features :( )
 |
 *===========================================================================*/

#include <iostream>

#include <string>

using namespace std;


// unnecessary
/*
bool isCorrect(char guessedCharacter){
	for(int i = 0; i<word.size();i++ ){

                isFound = (guessedCharacters.find( word[i]) != -1);
	
		if(isFound) return isFound;
	}
*/

string guessedString(string word, string charactersGuessed){
	string guessedSoFar = "";
        for(int i = 0; i<word.size();i++ ){

               if(charactersGuessed.find( word[i]) != string::npos){

                        guessedSoFar += word[i];}

                else{ guessedSoFar += "_";}

                }

        return guessedSoFar
;
		}



// this is one way to test is you have won or not
/*bool isComplete(string wordSoFar){
	if (wordSoFar.find('_') != string::npos)
		return true;// find
	else
    		return false;// not find
	
	}*/

string convertToUnderscore(string fromWord){
	string toWord="";
	for(int i = 0; i < fromWord.size(); i++){
		toWord+="_";
		}
	return toWord;
	}


bool displayStatus(string toWord, string wordProgress, string charactersGuessed, int mistakes){
	
	if(mistakes == 0){
		cout << 
		"   _____\n"

              <<"    |  |\n"

              <<"       |\n"

              <<"       |\n"

              <<"       |\n"

              <<"   ____|\n"
		<< endl;
		} // so far so good
	else if(mistakes == 1){
		cout << 
		"   _____\n"

              <<"    |  |\n"

              <<"    *  |\n"

              <<"       |\n"

              <<"       |\n"

              <<"   ____|\n"
		<< endl;
		}
	else if(mistakes == 2){
		cout << 
		"   _____\n"

              <<"    |  |\n"

              <<"    *  |\n"

              <<"    |  |\n"

              <<"       |\n"

              <<"   ____|\n"
		<< endl;
		}
	else if(mistakes == 3){
		cout << 
		"   _____\n"

              <<"    |  |\n"

              <<"    *  |\n"

              <<"   /|  |\n"

              <<"       |\n"

              <<"   ____|\n"
		<< endl;
		}
	else if(mistakes == 4){
		cout << 
		"   _____\n"

              <<"    |  |\n"

              <<"    *  |\n"

              <<"   /|\\ |\n"

              <<"       |\n"

              <<"   ____|\n"
		<< endl;
		}
	else if(mistakes == 5){
		cout << 
		"   _____\n"

              <<"    |  |\n"

              <<"    *  |\n"

              <<"   /|\\ |\n"

              <<"   /   |\n"

              <<"   ____|\n"
		<< endl;
		}
	else if(mistakes == 6){
		cout << 
		"   _____\n"

              <<"    |  |\n"

              <<"    *  |\n"

              <<"   /|\\ |\n"

              <<"   / \\ |\n"

              <<"   ____|\n"
		<< endl;
		return false;
		} //you lose
	else{
		cerr << "Unknown error count. Beep. System failure. *dies* x( " << endl;
		exit(1);
		}
	
	if(toWord == wordProgress){
		cout << "You win!" << endl;
		return false;
		}
	
	cout << wordProgress << endl;
	cout << charactersGuessed<< endl;
	
	return true;
	
	}

int main(){

    	string word = "papaya"; // this needs to be setin main
	string progressOnWord = "";
	string guessedCharacters = "";

	int errorCount = 0; // needs to be kept track of in main
	char guessedCharacter;
	progressOnWord = convertToUnderscore(word);
	
        cout << "=== Welcome to hangman! ===\n";


	// loop, prints status, which returns if you should continue or not	
	while(displayStatus(word, progressOnWord, guessedCharacters, errorCount)){

                cout << "Guess character (! to quit): ";

                cin >> guessedCharacter;

                if(guessedCharacter == '!'){return 0;}

                guessedCharacters+=guessedCharacter;

		if(word.find(guessedCharacter) == string::npos){
			errorCount++;
			}
                progressOnWord = guessedString(word, guessedCharacters);
		}

	cout << "The word is " << word << endl << "Thank you for playing!" << endl;
    return 0;

    }
