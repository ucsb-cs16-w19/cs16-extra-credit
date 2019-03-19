#include <iostream>
using namespace std;

/*=============================================================================
 |     Author: Gabriel Granados
 |   To Compile:  Download the Arduino software thats free on https://www.arduino.cc/en/Main/Software
 |        Class:  NAME AND TITLE OF THE CLASS FOR WHICH THIS PROGRAM WAS
 |                      WRITTEN
 |    Concepts:   FOR LOOPS, FUNCTIONS, IF-STATEMENTS 
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  THIS PROGRAM IS A WACKAMOLE GAME DESIGNED FOR THE ARDUINO UNO. THE FASTER THE USER PRESSES THE BUTTON LINKED
     WITH THE LIGHT THAT IS FLASHING, THE MORE POINTS ARE AWARDED. 
     
     
     WATCH THE VIDEO ON THE EXPLANATION FILE FOR MORE INFORMATION AND A DEMONSTRATION
 |
 |        Input: THE USER PRESSING THE BUTTONS ON THE ARDUINO UNO 
 |
 |       Output:  THE LIGHTS THAT REPRESENT THE MOLES AND THE POINTS 
 |
 |    Algorithm: NOT MUCH OF AN ALGORITHM. JUST A GAME. 
 |      PROBLEM.
 |
 |   Known Bugs:  IF THE PROGRAM DOES NOT FUNCTION CORRECTLY IN SOME
 |      SITUATIONS, DESCRIBE THE SITUATIONS AND PROBLEMS HERE.
 |
 *===========================================================================*/




//declares color locations on the board
const int red = 13;
const int blue = 12;
const int green = 11;
const int yellow = 10;
const int white = 9;

//declares button locations on board
const int but1 = 6;
const int but2 = 5;
const int but3 = 4;
const int but4 = 3;
const int but5 = 2;

//creates random number, initializes score to 0, sets game boolean to true, and creates tick (what is used to end game)
long randnumber;
int score = 0;
bool game = true;  
int tick;

//setup function 
void setup() {
  //creates random number up to that point
  randomSeed(analogRead(0));
  
  // declare the LED pins as outputs, 
  pinMode(red, OUTPUT); // red
  pinMode(blue, OUTPUT); // blue
  pinMode(green, OUTPUT); // green
  pinMode(yellow, OUTPUT); // yellow
  pinMode(white, OUTPUT); // white

  //declare buttons 
  pinMode(but1, INPUT_PULLUP);
  pinMode(but2, INPUT_PULLUP);
  pinMode(but3, INPUT_PULLUP);
  pinMode(but4, INPUT_PULLUP);
  pinMode(but5, INPUT_PULLUP);

//initializes the serial connection at 9600 bits per second.
  Serial.begin(9600);
}

void loop() {
  
  randnumber = random(50);      // random number is set to print a number from 0 to 49 
  if(game == true){ // sets game to be true so game starts (if statement) 

    
    Serial.println ("Hello welcome to Wack A Mole!"); 
    delay(2000);
    Serial.println ("There are three levels to this game, with each level getting progressively harder.");
    delay(3000);
    Serial.println ("In each level, 10 lights will flash and you must press the button before the light turns off."); 
    delay(4000);
    Serial.println("Each button press for its respective light will grant the player 10 points for a maximum score of 300 points.");
    delay(4000);   
    Serial.println("Good luck! The game will start in "); 
    delay(500); 
    Serial.println("3... ");
    delay(1000);
    Serial.println("2... ");
    delay(1000);
    Serial.println("1...");
    delay (1000);
  
  digitalWrite(red,HIGH);
  delay(1000);
  digitalWrite(blue,HIGH);
  delay(1000);
  digitalWrite(green,HIGH);
  delay(1000);
  digitalWrite(yellow,HIGH);
  delay(1000);
  digitalWrite(white,HIGH);
  delay(1000);
  digitalWrite(red,LOW);
  delay(500);
  digitalWrite(blue,LOW);
  delay(500);
  digitalWrite(green,LOW);
  delay(500);
  digitalWrite(yellow,LOW);
  delay(500);
  digitalWrite(white,LOW);
  delay(500);

   //************************************************************ Level 1 ********************************************************
      Serial.println ("-----------------------------------------------------Level 1-------------------------------------------------------------"); 
   //for loop that loops 10 times for the ten flashes per level  
   for (int i=0; i < 10; i++){  
      randnumber = random(50);
   //random number 0 - 9 = red, 10-19 = blue, 20-29 = green, 30-39 = yellow, 40-49 white 
      if (randnumber < 10){      
        digitalWrite(red, HIGH); //turn the red LED on
        // (until else if) if button red is pressed and button one is pressed, then add 10 to score and print score, and turn off all other lights 
        if (digitalRead(red) == HIGH){       
          delay(1000);    //delay one second 
          if(digitalRead(but1) == LOW){
            score += 10;        
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(blue, LOW);  // turn the blue LED off
        digitalWrite(green, LOW);  // turn the green LED off
        digitalWrite(yellow, LOW);  // turn the yellow LED off
        digitalWrite(white, LOW);   //turn the white LED off 
        delay (100);                //delay set to 1/10th of a second 
        digitalWrite(red, LOW); //turn the red LED off
 //same thing except for blue light within an else if 
      } else if (randnumber < 20){ 
        digitalWrite(red, LOW);  //turn the red LED off
        digitalWrite(blue, HIGH); // turn the blue LED on 
        if (digitalRead(blue) == HIGH){
          delay(1000);                 
          if(digitalRead(but2) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE:  ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(green, LOW);  
        digitalWrite(yellow, LOW);  
        digitalWrite(white, LOW);
        delay (100);
        digitalWrite(blue, LOW); // turn the green LED on pin 3 on
 //same thing except for green light 
      } else if (randnumber < 30) {
        digitalWrite(red, LOW);  //turn the green LED on pin 2 off
        digitalWrite(blue, LOW);  // turn the green LED on pin 3 off
        digitalWrite(green, HIGH); // turn the red LED on pin 4 on
        if ((digitalRead(green)== HIGH)){
          delay(1000);
          if(digitalRead(but3) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(yellow, LOW);  // turn the red LED on pin 5 off
        digitalWrite(white, LOW);
        delay (100);
        digitalWrite(green, LOW); // turn the red LED on pin 4 on
 // same thing except for yellow 
      } else if (randnumber < 40){
        digitalWrite(red, LOW); //turn the green LED on pin 2 off
        digitalWrite(blue, LOW); // turn the green LED on pin 3 off
        digitalWrite(green, LOW); // turn the red LED on pin 4 off
        digitalWrite(yellow, HIGH); // turn the red LED on pin 5 on
        if ((digitalRead(yellow)==HIGH)){
          delay(1000);
          if(digitalRead(but4) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println(score);
            Serial.println("****************");
          }
        }
        digitalWrite(white, LOW);
        delay (100);
        digitalWrite(yellow, LOW); // turn the yellow LED off
  //same thing except for white 
      } else if (randnumber < 50){
        digitalWrite(red, LOW); //turn the red LED off
        digitalWrite(blue, LOW); // turn the blue LED off
        digitalWrite(green, LOW); // turn the green LED off
        digitalWrite(yellow, LOW); // turn the yellow LED off 
        digitalWrite(white, HIGH);
        if ((digitalRead(white)==HIGH)){
          delay(1000);
          if(digitalRead(but5) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println(score);
            Serial.println("****************");
          }
        }
        delay (100);
        digitalWrite(white, LOW); // turn the red LED on pin 5 on
      }
      delay (100);
      tick = tick + 1;
   }
   
   //*************************************************************Level 2********************************************************
    Serial.println ("-----------------------------------------------------Level 2 ------------------------------------------------------------"); 
    for(int i = 0; i<1; i++){
        digitalWrite(red, HIGH); //turn the green LED on pin 2 off
        digitalWrite(blue, HIGH); // turn the green LED on pin 3 off
        digitalWrite(green, HIGH); // turn the red LED on pin 4 off
        digitalWrite(yellow, HIGH); // turn the red LED on pin 5 on
        digitalWrite(white, HIGH);
        delay (500);
        digitalWrite(red, LOW); //turn the green LED on pin 2 off
        digitalWrite(blue, LOW); // turn the green LED on pin 3 off
        digitalWrite(green, LOW); // turn the red LED on pin 4 off
        digitalWrite(yellow, LOW); // turn the red LED on pin 5 on
        digitalWrite(white, LOW);
    }

   for (int i=0; i < 10; i++){
      randnumber = random(50);
      if (randnumber <= 10){
        digitalWrite(red, HIGH); //turn the green LED on pin 2 on
        if (digitalRead(red) == HIGH){
          delay(1000);
          if(digitalRead(but1) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(blue, LOW);  // turn the green LED on pin 3 off
        digitalWrite(green, LOW);  // turn the red LED on pin 4 off
        digitalWrite(yellow, LOW);  // turn the red LED on pin 5 off
        digitalWrite(white, LOW);
        delay (100);
        digitalWrite(red, LOW); //turn the green LED on pin 2 on
      } else if (randnumber <= 20){
        digitalWrite(red, LOW);  //turn the green LED on pin 2 off
        digitalWrite(blue, HIGH); // turn the green LED on pin 3 on
        if (digitalRead(blue) ==HIGH){
          delay(1000);
          if(digitalRead(but2) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(green, LOW);  // turn the red LED on pin 4 off
        digitalWrite(yellow, LOW);  // turn the red LED on pin 5 off
        digitalWrite(white, LOW);
        delay (100);
        digitalWrite(blue, LOW); // turn the green LED on pin 3 on
      } else if (randnumber <= 30) {
        digitalWrite(red, LOW);  //turn the green LED on pin 2 off
        digitalWrite(blue, LOW);  // turn the green LED on pin 3 off
        digitalWrite(green, HIGH); // turn the red LED on pin 4 on
        if ((digitalRead(green)== HIGH)){
          delay(1000);
          if(digitalRead(but3) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(yellow, LOW);  
        digitalWrite(white, LOW);
        delay (100);
        digitalWrite(green, LOW); 
      } else if (randnumber <= 40){
        digitalWrite(red, LOW); 
        digitalWrite(blue, LOW); 
        digitalWrite(green, LOW); 
        digitalWrite(yellow, HIGH); 
        if ((digitalRead(yellow)==HIGH)){
          delay(1000);
          if(digitalRead(but4) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(white, LOW);
        delay (100);
        digitalWrite(yellow, LOW); // turn the yellow off
      } else if (randnumber <= 50){
        digitalWrite(red, LOW); 
        digitalWrite(blue, LOW); 
        digitalWrite(green, LOW); 
        digitalWrite(yellow, LOW); 
        digitalWrite(white, HIGH);
        if ((digitalRead(white)==HIGH)){
          delay(1000);
          if(digitalRead(but5) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        delay (100);
        digitalWrite(white, LOW); // turn the red LED on pin 5 on
      }
      
      delay (100);
      tick = tick + 1;
   }


   //************************************************************Level 3********************************************************
    Serial.println ("-----------------------------------------------------Level 3-------------------------------------------------------------"); 
    for(int i = 0; i<2; i++){
        digitalWrite(red, HIGH); //turn the Red LED on 
        digitalWrite(blue, HIGH); // turn the blue LED on 
        digitalWrite(green, HIGH); // turn the green LED on 
        digitalWrite(yellow, HIGH); // turn the yellow LED on
        digitalWrite(white, HIGH);  //turn the white LED on 
        delay (500);
        digitalWrite(red, LOW); //turn the green LED on pin 2 off
        digitalWrite(blue, LOW); // turn the green LED on pin 3 off
        digitalWrite(green, LOW); // turn the red LED on pin 4 off
        digitalWrite(yellow, LOW); // turn the red LED on pin 5 on
        digitalWrite(white, LOW);
        }

   for (int i=0; i < 10; i++){
      randnumber = random(50);
      if (randnumber <= 10){
        digitalWrite(red, HIGH); //turn the green LED on pin 2 on
        if (digitalRead(red) == HIGH){
          delay(750);
          if(digitalRead(but1) == LOW){
            score += 10; 
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(blue, LOW);  // turn the green LED on pin 3 off
        digitalWrite(green, LOW);  // turn the red LED on pin 4 off
        digitalWrite(yellow, LOW);  // turn the red LED on pin 5 off
        digitalWrite(white, LOW);
        delay (50);
        digitalWrite(red, LOW); //turn the green LED on pin 2 on
      } else if (randnumber <= 20){
        digitalWrite(red, LOW);  //turn the green LED on pin 2 off
        digitalWrite(blue, HIGH); // turn the green LED on pin 3 on
        if (digitalRead(blue) ==HIGH){
          delay(750);
          if(digitalRead(but2) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(green, LOW);  // turn the red LED on pin 4 off
        digitalWrite(yellow, LOW);  // turn the red LED on pin 5 off
        digitalWrite(white, LOW);
        delay (50);
        digitalWrite(blue, LOW); // turn the green LED on pin 3 on
      } else if (randnumber <= 30) {
        digitalWrite(red, LOW);  //turn the green LED on pin 2 off
        digitalWrite(blue, LOW);  // turn the green LED on pin 3 off
        digitalWrite(green, HIGH); // turn the red LED on pin 4 on
        if ((digitalRead(green)== HIGH)){
          delay(750);
          if(digitalRead(but3) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(yellow, LOW);  // turn the red LED on pin 5 off
        digitalWrite(white, LOW);
        delay (50);
        digitalWrite(green, LOW); // turn the red LED on pin 4 on
      } else if (randnumber <= 40){
        digitalWrite(red, LOW); //turn the green LED on pin 2 off
        digitalWrite(blue, LOW); // turn the green LED on pin 3 off
        digitalWrite(green, LOW); // turn the red LED on pin 4 off
        digitalWrite(yellow, HIGH); // turn the red LED on pin 5 on
        if ((digitalRead(yellow)==HIGH)){
          delay(750);
          if(digitalRead(but4) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(white, LOW);
        delay (50);
        digitalWrite(yellow, LOW); // turn the red LED on pin 5 on
      } else if (randnumber <= 50){
        digitalWrite(red, LOW); //turn the green LED on pin 2 off
        digitalWrite(blue, LOW); // turn the green LED on pin 3 off
        digitalWrite(green, LOW); // turn the red LED on pin 4 off
        digitalWrite(yellow, LOW); // turn the red LED on pin 5 on
        digitalWrite(white, HIGH);
        if ((digitalRead(white)==HIGH)){
          delay(750);
          if(digitalRead(but5) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        delay (50);
        digitalWrite(white, LOW); // turn the red LED on pin 5 on
      }
      
      delay (50);
      tick = tick + 1;
   }

    for(int i = 0; i < 6; i++){
        digitalWrite(red, HIGH); //turn the red LED on 
        digitalWrite(blue, HIGH); // turn the blue LED on 
        digitalWrite(green, HIGH); // turn the green LED on 
        digitalWrite(yellow, HIGH); // turn the yellow LED on 
        digitalWrite(white, HIGH);  //turn the white LED on  
        delay (500);             //delays for 500 milliseconds 
        digitalWrite(red, LOW); 
        digitalWrite(blue, LOW); 
        digitalWrite(green, LOW); 
        digitalWrite(yellow, LOW); 
        digitalWrite(white, LOW);  
    }
    
     if (tick == 30){
      game = false;
      Serial.print("Game over! Your score was "); 
      Serial.print(score); 
      Serial.println(" / 300"); 

     }
 }
}
  
