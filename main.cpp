#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

/*=============================================================================
 |     Author:    Cai An
 |   To Compile:  simply type "make project"  
 |
 |        Class:  6:30 pm
 |    Concepts:   I will use the knowledge of Array and what I have learnt from the internet about  multidimensional array
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  The program does multiplication for matrixes
 |
 |        Input:  the program will ask the user to input several lines of numbers to form two matrixes
 |
 |       Output:  The program will return the result after multiplication
 |
 |    Algorithm:  Pretty much what I learnt from Math4A which helps me to multiply matrix
 |
 |   Known Bugs:  IF THE PROGRAM DOES NOT FUNCTION CORRECTLY IN SOME
 |      SITUATIONS, DESCRIBE THE SITUATIONS AND PROBLEMS HERE.
 |
 *===========================================================================*/

int main () {
int a[10][10]={0},b[10][10]={0},c[10][10]={0};
  int space_index(0),ColNum(0),RowNum(0),ColNum1(0),RowNum1(0);
  string row="";
  cout<<"Enter first matrix:"<<endl; //asking the user to enter the first matrix
  getline(cin,row);
  while (row!="")
  {
    row=row+' ';
    ColNum=0;
    while (row!="")
    {
      space_index=row.find(' ');
      a[RowNum][ColNum]=stoi(row.substr(0,space_index));
      // get the first number from a line and store them in the array
      row=row.substr((space_index+1),(row.length()-space_index-1));
      // renew the line by storing all the numbers after the first number
      ColNum++;
      //count the columns of the first matrix
    }
    RowNum++; //count the rows of the first matrix
    getline(cin,row); //get a new line to read numbers from
  }
  cout<<"Enter second matrix:"<<endl; //asking the user to enter the second matrix
  getline(cin,row);
  while (row!="")
  {
    row=row+' ';
    ColNum1=0;
    while (row!="")
    {
      space_index=row.find(' ');
      b[RowNum1][ColNum1]=stoi(row.substr(0,space_index));
      row=row.substr((space_index+1),(row.length()-space_index-1));
      ColNum1++;
    }
    RowNum1++;
    getline(cin,row);
  } //works exactly the same as the first matrix
  if (ColNum!=RowNum1)
  {
    cout<<"The two matrices have incompatible dimensions."<<endl;
    //checking if the columns of the first matrix is equal to the rows of the the second matrix, which is the prerequist for multiplication
    exit(1); //exit because of error
  }
  else
  {
    for (int i=0;i<RowNum;i++)
    {
      for (int j=0;j<ColNum1;j++)
      {
	for (int k=0;k<ColNum;k++)
	{
	  c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
	  //calculate the elements of the product matrix
        }
      }
    }
    cout<<"The product is:"<<endl;
    for (int i=0;i<RowNum;i++)
    {
      for (int j=0;j<ColNum1;j++)
      {
	if (j==ColNum1-1)
        {
	  cout << c[i][j];
        }
        else
        {
	  cout<<c[i][j]<<" ";
        }
      }
        cout << endl;
    } 
    return 0;
  }
}
