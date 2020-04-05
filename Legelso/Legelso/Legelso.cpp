#include "pch.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitX,fruitY,score;
int tailX[100], tailY[100];
int lTail;
enum eDirection { STOP = 0, LEFT,RIGHT, UP, DOWN };
eDirection dir;
void Setup() {
	gameOver = false;

	dir = STOP;
	x = width / 2;
	y = height / 2;
	srand(time(NULL));
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;

}

void Draw() {

	system("cls");
	for (int i = 0; i < width+1; i++)
	{
		cout << "°";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j==0)
			{
				cout << "°";
			}
			if(i == y && j == x) {
				cout << "O";
			}
			else if(i == fruitY && j == fruitX){

				cout << "$";
			}
			else {
				bool print = false;
				for (int k = 0; k < lTail; k++)
				{
					
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				
				}
				if (!print)
				{
					cout << " ";
				}
				
			}

			if (j == width-2)
			{
				cout << "°";

			}
			
		}
		cout << endl;

	}

	for (int i = 0; i < width+1; i++)
	{
		cout << "°";
	}
	cout << endl;

	cout << "Score: " << score;

}

void Input() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':dir = LEFT; break;
		case 'd':dir = RIGHT; break;
		case 'w':dir = UP; break;
		case 's':dir = DOWN; break;
		case 'x':gameOver = true; break;
		
		} 
	}


}

void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;

	for (int i = 0; i < lTail;i ++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
		tailX[0] = x;
		tailY[0] = y;
	}

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (x >= width-2 || x <= 0 || y >= height-1 || y <= 0)
	{

		dir = STOP;

	}
	for (int i = 0; i < lTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			gameOver = true;

		}

	}
	if (x ==fruitX && y == fruitY)
	{
		
		srand(time(NULL));
		fruitX = rand() % width;
		fruitY = rand() % height;
		score++;
		lTail++;

	}

	

}

int main()
{
	Setup();

	while(!gameOver){
	

		Draw();
		Input();
		Logic();

	}


	return 0;
    
}

