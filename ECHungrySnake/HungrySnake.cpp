#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <GLUT/GLUT.h>
#include <list>

using namespace std;

/*=============================================================================
 |     Author:    JUNTONG JING
 |   To Compile:  make -f makefile.macosx 
 |
 |        Class:  CS16
 |            
 |    Concepts:  for loop, if else, switch, while loop, structure, function, pointer, list
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  It is a game to save people from feeling bored. :)
 |
 |        Input:  g-Start; e-Up, d-Down, s-Left, f-Right; q-Quit
 |
 |       Output:  A window, a snake, and apples(all are made of blocks).
 |
 |    Algorithm:  OUTLINE THE APPROACH USED BY THE PROGRAM TO SOLVE THE
 |      PROBLEM.
 |
 |   Known Bugs: No bugs, but there're lots of warnings because of the OpenGL. 
 |      
 |
 *===========================================================================*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <GLUT/GLUT.h>
#include <list>

using namespace std;

const int TimerInterval = 250; //Use time interval to control the speed of Snake

struct Pos{
  int r, c; // row and column
  Pos(int r=0, int c=0): r(r), c(c) {} //Initial coordinates(row, column)
  bool operator==(const Pos& other) const { return r==other.r && c==other.c; }
};

class HungrySnake 
{
public:
  enum {RowLim=20, ColLim=RowLim}; //Limit to 20 rows and columns
  enum EnumStatus {Preparing, Started, GameOver};  
  enum EnumDirection {Up, Down, Left, Right};
  
  bool gameOver() const { return status == GameOver; }
  bool preparIng() const { return status == Preparing; }
  void start() { status = Started; }

  const list<Pos>& getSnake() { return snake; }
  const Pos& getFoodPos() { return foodPos; }

  HungrySnake(): status(Preparing), currentDir(Right) 
  {
    srand(time(NULL)); //Preparing: set timer to NULL
    createApple(); //Create an "apple"    
    snake.insert(snake.begin(), {{0,2}, {0,1}, {0,0}}); //Snake's begin position
  }

  void setDirection(EnumDirection dir) 
  { 
      currentDir = dir; 
  }

  bool move() //Track the position
  {
    Pos headPos = beginMove(currentDir);
    if (hitTheWall(headPos) || eatItself(headPos)) 
    { 
      status = GameOver; 
    } 
    else if (headPos == foodPos) //Eat the apple
    {
      snake.push_front(headPos); //Increase a block on Snake's body
      createApple();
    } 
    else //Nothing happened, keeping moving.
    {
      snake.push_front(headPos); //Head move forward.
      snake.pop_back(); //Delete one block from the tail.
    }
    return status != GameOver;
  }


private:
  Pos beginMove(EnumDirection dir) 
  {
    Pos headPos = snake.front();
    switch(dir)
    {
    case Up:
            headPos.r--;
            break;
    case Down:
            headPos.r++;
            break;
    case Left:
            headPos.c--;
            break;
    case Right:
            headPos.c++;
            break;
    } //Move the head by changing the coordinates (row,column)
    return headPos;
  } 

  bool eatItself(const Pos& headPos) 
  {
    for(const Pos& pos: snake)
      if (headPos == pos)
        return true;
    return false;
  }

  void createApple() 
  {
    do 
    {
      foodPos.r = rand() % RowLim;
      foodPos.c = rand() % ColLim;
    }while (eatItself(foodPos));
  } //If an apple is eaten, create another apple randomly

  bool hitTheWall(const Pos& headPos) 
  {
    return headPos.r < 0 || headPos.r >= RowLim ||
           headPos.c < 0 || headPos.c >= ColLim;
  }


private:
  list<Pos> snake;
  Pos       foodPos;
  EnumDirection  currentDir;
  EnumStatus     status;
} gHungrySnake;

//OpenGL: 
void drawBlock(const Pos& pos) 
{
  static const GLfloat BlockSize = 2.0f / HungrySnake::RowLim;
  static const GLfloat Padding = BlockSize * 0.1f;
  GLfloat x = pos.c * BlockSize - 1.0f, y = 1.0f - pos.r * BlockSize;
  glRectf(x+Padding, y-Padding, x+BlockSize-Padding, y-BlockSize+Padding);
}

void display()  
{  
  
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Background
 
  glColor3f(0.2f, 0.6f, 0.2f);
  for(auto& pos: gHungrySnake.getSnake()) 
  { 
       drawBlock(pos); 
  } // Snake's body
  
  glColor3f(0.3f, 0.9f, 0.3f);
  drawBlock(gHungrySnake.getSnake().front()); // Snake's head
  
  glColor3f(1.0f, 0.2f, 0.2f);
  drawBlock(gHungrySnake.getFoodPos()); // Food

  glFlush();
} //Using OpenGL to create background, body, head and food (all blocks). With the help of Google.

void timer(int timerId) 
{
  if (timerId == 1) 
  {
    if (gHungrySnake.move()) 
    {
      display();
      glutTimerFunc(TimerInterval, timer, 1);
    } 
  }
} //Timer

void keyBoard(unsigned char key, int x, int y) 
{
  if (key == 'q')  
  	exit(0);  // Response to 'q' even after game over
  if (gHungrySnake.gameOver())  
  	return; 
  if (gHungrySnake.preparIng()) 
  {
    if (key == 'g') 
    { 
    	gHungrySnake.start(); 
    	glutTimerFunc(TimerInterval, timer, 1); 
    }
  } 
  else //Game starts here 
  {
     if(key == 'e') 
    	gHungrySnake.setDirection(HungrySnake::Up); 
    else if (key == 'd') 
	gHungrySnake.setDirection(HungrySnake::Down); 
    else if (key == 's') 
	gHungrySnake.setDirection(HungrySnake::Left); 
    else if (key == 'f')  
	gHungrySnake.setDirection(HungrySnake::Right); 
  }
}

int main(int argc, char ** argv)  
{  
  printf("Instructions:\n g-Start;\n e-Up, d-Down, s-Left, f-Right;\n q-Quit.\n");
  glutInit(&argc, argv);  
  glutInitWindowSize(700, 700);  
  glutCreateWindow("g-Start | e,d,s,f-Directions | q-Quit");  
  glutDisplayFunc(display);  
  glutKeyboardFunc(keyBoard);
  glutMainLoop(); 
  return 0;
}