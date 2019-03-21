#include <iostream>
using namespace std;

/*=============================================================================
 |     Author:    Luka Vukmanovic
 |   To Compile:  
 |
 |        Class:  CS16 Call By Reference
 |    Concepts:   It uses concepts of call by references and call by values and shows how they each affect differently
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  What is the output of the following code?
 |      SOLVE.
 |
 |        Input:  #include <iostream>
void figure_me_out(int& x, int y, int&z);
int main()
{
using namespace std;
int a,b,c;
a=10;
b=20;
c=30;
figure_me_out(a,b,c);
cout<< a << “ “ << b << “ “ << c;
return 0; }
void figure_me_out (int& x, int y, int& z){
          cout<< x << “ “ << y << “ “ << z;
x=1;
y=2;
z=3;
 cout << x << “ “ << y << “ “ << z;
}

 |
 |       Output:  10 20 30
                   1  2  3
                   1 20  3
 |
 |    Algorithm:  He swaps some values between a b c and x y z due to the pass by reference calls.
 |
 |   Known Bugs:  Be careful about the references.
 |
 *===========================================================================*/

int main () {

    return 0;
}
