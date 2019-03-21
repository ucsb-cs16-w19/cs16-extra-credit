#include <iostream>

using namespace std;

/*=============================================================================
 |     Author:    HANCHENG GONG (9499088)
 
 |   To Compile:  Follow the instructions which is enter the current date and a user's birthdate in order to calculate the user's exact age
 |
 |        Class:   CS16 WINTER 2019
 |                      
 |    Concepts:   I had used basice concepts of c++ such as cin,cout,assign variables,function declaration, function defnitions, if statement and switch/case
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:   This program is created for the users who is interesting to know their exact age
 |     .
 |
 |        Input:  It requires to input today's date and user's birthday
 |
 |       Output:  The output will show user's age in years, months, and days. Also if today is user's birthday, it will show happy birthday!
 |
 |    Algorithm:  Not much calculations invloved except the part where to calculate the user's age, but there are a lot of logical and relational operators involved 
 |
 |   Known Bugs:  I cannot identify any bug for now, the program works smoothly.
 |
 *===========================================================================*/
 
 
 
 
 
 

//function definitions


//function to extract dates

bool today (int&month, int&day, int&year, const int guess) {

    bool good;
    int count = 1;

    bool goodDate(int&, int&, int&);

    cout << "as MM DD YYYY: ";
    cin >> month >> day >> year;

    good = goodDate(month, day, year);

    if (good == false) {
        while (good == false && count < guess) {
            count++;
            cout << "The entered date is not good, please re-enter: ";
            cin >> month >> day >> year;
            good= goodDate(month, day, year);

        }

    cout << "You have reached the limit for no-good dates." << endl;
    }

    return(good);

}

// function which allows  users to enter their births

bool birthDate (int cmonth, int cday, int cyear, int&bmonth, int&bday, int&byear, const int guess) {

    bool good;
    bool good2;

    bool today (int, int, int, int, int, int);
    bool today (int&, int&, int&, const int);

    cout << "Please enter your bitrth-day, ";

    good = today(bmonth, bday, byear, guess);


    if (good == true)
        good2 = today(cmonth, cday, cyear, bmonth, bday, byear);

    return(good2);

}



bool today (int cmonth, int cday, int cyear, int bmonth, int bday, int byear) {

    bool good;



    if (byear > cyear)
        good = false;
    else


    if (byear == cyear) {


        if (bmonth < cmonth) 
            good = true;
        else

    
        if (bmonth == cmonth)

          
            if (bday < cday)
               good= true;
            else
        
                good= false;
        else

    

        if (bmonth > cmonth)
            good = false;
    else
    
    if (byear < cyear)
        good = false;
    }

    return(good);
}


//function which uses variables of day, month, and year to make sure that the date entered is good 

bool goodDate (int&month, int&day, int&year) {


    bool good;
    int daylimit;

    //function declaration
    int getLastDay (int);


   daylimit = getLastDay(month);


    if (month < 0 || month > 12)
        good = false;

    else

 

    if (month > 0 && month <= 12) {
        if (day > 0 && day <= daylimit)
            good = true;
        else
            good = false;
    }

    return (good); 
}


    int getInt(int y, int m, int d)
{
    int x = y*365;

    //function declaration
    
    int getLastDay (int);

    for (int i = 1; i<m; i++)
        x+=getLastDay(i);
        x+=d;
        
    return x;
}

//function calculate ages by bmonth, bday, byear,cmonth, cday, and cyear 

void agecal (int bmonth, int bday, int byear, int cmonth, int cday, int cyear, int&aYear, int&aMonth, int&aDay) {


   
    int daylimit;

    //function declaration
    
    int getLastDay (int);


    int now = getInt(cyear,cmonth,cday);
    int birth = getInt(byear,bmonth,bday);
    if(now<birth) return;
    int difference = now-birth;
    aYear = (difference)/365;

    difference-=(365*aYear);

    aMonth = 0;
    int rest;
    while(1)
    {
        rest = getLastDay(aMonth+1);
        if(difference>=rest)
        {
            difference-=rest;
            aMonth++;
        }
        else break;
    }
    aDay = difference;
}


//function uses the month entered to calculate the maximum good days for that month

int getLastDay (int month) {

    int daylimit;

    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            daylimit = 30;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            daylimit = 31;
            break;
        case 2:
            daylimit = 28;
    }

    return(daylimit);
}




//The main function



int main () {

    //declare local variables
    
    bool good, goodbirth;
    int cmonth, cday, cyear;
    int bmonth, bday, byear;
    int aYear, aMonth, aDay;
    char result;
    const int guess = 3;

    //function declarations
    
    bool today (int&, int&, int&, const int);
    bool birthDate (int, int, int, int&, int&, int&, const int);
    void agecal (int, int, int, int, int, int, int&, int&, int&);

    
    cout << "Please enter today's date, ";
    good = today(cmonth, cday, cyear, guess);

   
    if (good == false)
        cout << endl;
    else

  
    if (good == true) {
        cout << "Date entered is: " << cmonth << '/' << cday << '/' << cyear << endl;

        cout << "Do you care to know how old are you (y/n)? ";
        cin >> result;

        if (result == 'N' || result == 'n')
            cout << "OK" << endl;
        else

    
    
        if (result == 'Y' || result == 'y') {
            if (goodbirth = birthDate (cmonth, cday, cyear, bmonth, bday, byear, guess) == true) {

            cout << "Date entered is: " << bmonth << '/' << bday << '/' << byear << endl;       

           
            agecal(bmonth, bday, byear, cmonth, cday, cyear, aYear, aMonth, aDay);

            
            cout << "You are " << aYear << " years, " << aMonth << " months, and " << aDay << " days old." << endl;

            
            if (bmonth == cmonth && bday == cday)
                cout << "Happy birthday!" << endl;
            }

            else
                cout << " No-Good birthday." << endl;

        } 

        else 
            cout << "Please enter 'y' or 'n'" << endl;


    } 
}
