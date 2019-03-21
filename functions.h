// Mathew Kramsch
// functions.h
// function declarations for functions used in main.cpp

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

void printline();

void start_message(string quiz_file);

void quiz_term(int q_num, int &num_wrong, string term, string def, char &cont);

void quiz_function(ifstream &ifstream_file);
