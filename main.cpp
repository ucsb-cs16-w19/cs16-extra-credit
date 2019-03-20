#include <iostream>
#include <string>
using namespace std;

/*=============================================================================
 |     Author:   Danming Wang
 |   To Compile:  g++ -o main main.cpp
 |
 |        Class:  string recVowels(string s)
 |                    
 |    Concepts:   This program uses recursion and string functions.
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  This program is written to find what vowels are contained in the input string.
 |
 |        Input:  a string consists of letters.
 |
 |       Output:  a string that contains only the vowels in order of appearance in the input string
 |
 |    Algorithm:  set the base case, which is when searching to the end of the input string, i.e. s.length()==0; Then try to write a recursive call to reach the base case.
 |
 |   Known Bugs:  The base case is wrong. Or the recursive call fails to reach the base case. Or foget to consider the uppercase and lower case of each character.
 |
 *===========================================================================*/

string recVowels(string s){
	string vowel = "aeiouAEIOU";
	string emp = "";
	int len = s.length();
	if (len == 0){
		return emp;}
	else {
		if (vowel.find(s[0])!=-1){
			return s[0]+ recVowels(s.substr(1,len-1));}
		else {
			return recVowels(s.substr(1,len-1));}
	}
}

int main () {
	cout << "Vowels in 'apple': "<< recVowels("apple")<< endl;
	cout << "Vowels in 'ApPle': "<< recVowels("ApPle")<< endl;
	cout << "Vowels in 'computer science': "<< recVowels("computer science")<< endl;
	return 0;
}
