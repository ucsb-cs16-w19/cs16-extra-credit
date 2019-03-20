#include <iostream>
using namespace std;

/*=============================================================================
 |     Author:    Joe Zhuang
 |   To Compile:  simply type ./main width height after compiling 
 |                example:( ./main 4 6)
 |        Class:  CS 16 :Problem Solving I. (Professor K.)
 |    Concepts:   utilize loops and stars
                  to output short sentences with images.
 +-----------------------------------------------------------------------------
 |
 |  Description:  output CS16 with stars
 |
 |        Input:  width and height of each letter.
 |
 |       Output:  the image of letters
 |
 |    Algorithm:  for loops
 |
 |   Known Bugs:  if the width and height of each letter are assigned to different values, the images of each letter will be abnormal.
     letter 'S' looks like number '5'
     hard to perform 'S' and '6' smoothly.
     fail to output "CS16" in the same line.
 |
 *===========================================================================*/
string starC(int width, int height){
	string result = "";
	if(width < 2 || height < 5){
		return result;
	}
	for (int i = 0; i < width + 1; i++){
		result += "*";
	}
	result += "\n";
	for (int i = 0; i < height - 3; i++){
		result += "*";
		for ( int j = 0; j < width - 1; j++){
			result += " ";
		}
		result += "\n";
		
	}
	for (int i = 0; i < width + 1 ; i++){
		result += "*";
	}
	result += "\n";
	return result;
	}

string starS(int width, int height){
	string result = "";
	if (width < 3 || height < 5){
		return result;
	}
	for (int i = 0; i < width; i++){
		result += "*";
	}
	result += "\n";
	for (int i = 0; i <= height/2 - 2; i ++){
		result += "*";
		result += "\n";
	}
	for (int i = 0 ; i < width; i++){
		result += "*";
	}
	result += "\n";
	for (int i = 0; i < width - 2 ; i++){
		for (int j = 0; j < width; j++){
			result += " ";
		}
		result += "*";
		result += "\n";

	}	
	for (int i = 0; i < width ; i++){
		result += "*";
	}
	result += "\n";
	return result;
	}

string star1(int height){
	string result = "";
	if (height < 1){
		return result;
	}
	for (int i = 0; i < height; i++){
		result += "*";
		result += "\n";
	}
	return result;
}
string star6(int width, int height){
	string result = "";
	if (width < 3 || height < 3){
		return result;
	}
	for (int i = 0; i < width; i++){
		result += "*";
	}
	result += "\n";
	for (int i = 0; i < height - 4; i++){
		result += "*";
		result += "\n";
	}
	for ( int i = 0; i < width; i ++){
		result += "*";
	}
	result += "\n";
	for (int i = 0; i < width - 2; i++){
		result += "*";
		for (int j = 0; j < width - 2; j++){
			result += " ";
		}
		result += "*";
		result += "\n";
	}
	for ( int i = 0; i < width; i++){
		result += "*";
	}

	return result;
}


int main (int argc, char* argv[]) {
	if (argc != 3){
		cerr << "please enter 3 arguments" << endl;
		exit(1);
	}
	int width = stoi(argv[1]);
	int height = stoi(argv[2]);
	cout << starC(width, height) << endl;
	cout << starS(width, height) << endl;
	cout << star1(height) << endl;
	cout <<star6(width, height) << endl;
    return 0;
}
