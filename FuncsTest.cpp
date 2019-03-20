#include<iostream>
#include"struct.h"
#include"Funcs.h"
#include<string>
using namespace std;


void assertEquals(std::string expected,
		  std::string actual,
		  std::string message) {
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl
	 << "   Expected:[\n"
	 << expected << "] actual = [\n"
	 << actual << "]\n" << endl;
  }
}


int  main(){
	string resualt1="countless 4\ncountless 601\ncountless 909\n";
	string resualt2="NA 0\nNA 0\nNA 0\n";
	string case1 = mainForTesting("countless");
	string case2 = mainForTesting("Odysseus");
	assertEquals(resualt1,case1,"mainForTesting(countless)");
	assertEquals(resualt2,case2,"mainForTesting(Odysseus)");
	return 0;	

}

