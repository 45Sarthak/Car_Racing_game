#include<iostream>
#include<conio.h>
#include<windows.h> //mainly used for sleep function
#include<time.h>// mainly used for generation random entaties

using namespace std;

bool exitGame;
bool gameOver;
bool isMoving;
bool bombExplode;
bool dead;
int height;
int width;
int life=5;
int score;
int speed;
int myCarX;
int myCarY;
int highScore;
int highestScore[5];
int enemyX[4];
int enemyY[4]={-8,-18,-28,-38};
int enemyPositionX;
int enemyPositionY;
int enemyNum;

string bombParticle1[4]={"o   o"," ooo "," ooo ","o   o"};
string bombParticle2[4]={" ooo ","o   o","o   o"," ooo "};

string myCar[4]={" # ",   //<-----Structure of Car--->
                 "# #",
                  "#",
                 "# #"};

void gotoxy(int x,int y) //gotoxy is used for to print in any place you want 
{
    COORD coord;
    coord.X=X;
    coord.Y=Y;
    setConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void hidcursor()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize=100;//The percentage of the character cell that is filled by the cursor
    cursor.bVisible=false;// The visibility of the cursor
    setConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor);
}

void startup() //All values Once the game Start.
{
    srand(time(NULL));
    exitGame=false;
    isMoving=false;
    gameOver=false;
    dead=false;
    height=20;
    width=19;
    myCarX=8;
    myCarY=16;
    speed=1;
    enemyNum=4;
    score=0;


    for(int i=0i<enemyNum;i++)
    {
        enemyPositionX=rand()%3;
        if(enemyPositionX==0) enemyX[i]=2;
        else if(enemyPositionX==1) enemyX[i]=8;
        else if(enemyPositionX==2) enemyX[i]=14;

    }
    enemyY[0]=-8;
    enemyY[1]=-18;
    enemyY[2]=-28;
    enemyY[3]=-38;
}

void layOut()//OverAll layout of Game
{
    for(int i=0;i<height;i++)
    {
        gotoxy(0,1);cout<< "#                         #";
        if(i% 2==0 && isMoving)
        {
            gotoxy(6,i);cout<<"|        |";
        }
        else if(i%2 !=0 && !isMoving)
        {
            gotoxy(6,i);cout<<"|        |";
        }
    }
    gotoxy(5,21); cout<<"Life :"<<life;
    gotoxy(5,22);cout<<"score :"<<score;
}

void drawMycar() // My car Structure.
{
    if(!dead)
    {
        for(int i=0; i<4; i++)
        {
            gotoxy(myCarX,myCarY+1); cout<< mycar[i];
        }
    }else
    {
        for(int i=0;i < myCarY+1;i++)
        {
            gotoxy(myCarX,myCarY+1);cout<<"     ";
        }
    }
}

void drawEnemyMycar()
{
    for(int i=0;i<enemyNum;i++)
    {
        if(enemyY[i]+3 >0)
        {
            gotoxy(enemyX[i],enemyY[i]+3)
            cout<<" # ";
        }
        if(enemyY[i]+2> 0)
        {
            gotoxy(enemyX[i], enemyY[i]+2);
            cout<<" # ";
        }

    }
}








