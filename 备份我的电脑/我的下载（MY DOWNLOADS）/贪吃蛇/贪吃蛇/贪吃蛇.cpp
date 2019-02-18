#include"pch.h"
#include<iostream>
#include "Wall.h"
#include "Snake.h"
#include <random>
#include "Food.h"
#include <Windows.h>
#include<conio.h>
#include <cstddef>
#include <string>
using namespace  std;


void hideCursor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
}
int main()
{

	hideCursor();

	int speed = 0;
	int mode = 0;
	//string title = "title 催眠贪吃蛇-----kaine-----Daata : 2019 / 1 / 16     模式:正常模式                  分数:" + std::to_string(score);
start:string title = "title 催眠贪吃蛇-----kaine-----Daata : 2019 / 1 / 16";
	system(title.c_str());
	cout << "请输入游戏难度,W S A D键 控制方向" << endl;
	cout << "1--------正常模式" << endl;
	cout << "2--------困难模式" << endl;
	cout << "3--------变态模式" << endl;
	char c = _getch();
	switch (c)
	{
	case '1':	mode = 1; system("mode con cols=80 lines=42"); speed = 150;	title = "title 催眠贪吃蛇-----kaine-----Daata : 2019 / 1 / 16     模式:正常模式"; system(title.c_str()); break;
	case '2':	mode = 2; system("mode con cols=80 lines=42"); speed = 100; title = "title 催眠贪吃蛇-----kaine-----Daata : 2019 / 1 / 16     模式:困难模式"; system(title.c_str()); break;
	case '3':	mode = 3; system("mode con cols=80 lines=42"); speed = 50; title = "title 催眠贪吃蛇-----kaine-----Daata : 2019 / 1 / 16     模式:变态模式"; system(title.c_str()); break;
	default:system("cls"); goto start; break;
	}


	bool isDead = false;


	Wall wall;
	Food food(wall);
	Snake snake(wall, food, mode);
	wall.initWall();
	wall.drawWall();
	snake.initSnake();
	food.setFood();

	while (!isDead)
	{
		char key = _getch();


		if (snake.lastKey == NULL && key == snake.LEFT)
		{
			continue;
		}




		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				if (snake.lastKey == NULL)
					snake.lastKey = key;
				else
				{

					if (key == snake.UP&&snake.lastKey == snake.DOWN ||
						key == snake.DOWN&&snake.lastKey == snake.UP ||
						key == snake.LEFT&&snake.lastKey == snake.RIGHT ||
						key == snake.RIGHT&&snake.lastKey == snake.LEFT
						)
					{
						key = snake.lastKey;
					}
					else
					{
						snake.lastKey = key;
					}
				}


				if (snake.move(key))
				{
					//system("cls");
					//wall.drawWall();
					Sleep(speed);
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key = snake.lastKey;
			}

		} while (!_kbhit());




	}
	cout << "分数:" + snake.score << "    是否继续? 继续输入 1,退出输入 0";
	char cc;

	do
	{
		 cc= _getch();
	} while (cc != '1' && cc != '0');
		if (cc == '1')
		{
			system("cls");
			goto start;
		}
		else
			return 0;


}