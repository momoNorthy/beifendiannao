#include "pch.h"
#include "Snake.h"
#include <cstddef>
#include <iostream>
#include <string>


void Snake::initSnake()
{
	destroyPoint();
	addPoint(5, 5);
	addPoint(5, 6);
	addPoint(5, 7);
}

void Snake::destroyPoint()
{
	Point *pCur = pHead;
	while (pHead)
	{
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

void Snake::addPoint(int x, int y)
{

	Point *newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = nullptr;
	if (pHead)
	{
		wall.setWall(pHead->x, pHead->y, '=');
	}
	newPoint->next = pHead;

	pHead = newPoint;

	wall.setWall(newPoint->x, newPoint->y, '@');
}

void Snake::delPoint()
{
	if (!pHead || !pHead->next)
	{
		return;
	}
	Point *pCur = pHead->next;
	Point *pPre = pHead;
	while (pCur->next)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	wall.setWall(pCur->x, pCur->y, ' ');
	delete pCur;
	pCur = nullptr;
	pPre->next = nullptr;
}

bool Snake::move(char key)
{
	size_t x = pHead->x;
	size_t y = pHead->y;
	switch (key)
	{
	case UP:--x; break;
	case DOWN:++x; break;
	case RIGHT:++y; break;
	case LEFT:--y; break;
	}


	Point *pCur = pHead->next;
	Point *pPre = pHead;
	while (pCur->next)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}

	if (pCur->x == x && pCur->y == y)
	{
		//碰到尾巴
		isRool = true;
	}
	else
	{
		if (wall.getWall(x, y) == '=' || wall.getWall(x, y) == '*')
		{
			addPoint(x, y);
			if(wall.getWall(x, y) == '=')
			delPoint();
			//system("cls");
			//wall.drawWall();
			wall.gotoxy(1, wall.ROW+1);
			std::cout << "GameOver" << std::endl;
			return false;
		}

	}
	if (wall.getWall(x, y) == '#')
	{
		++score;
		std::string title;
		switch (mode)
		{
		case 1: title = "title 催眠贪吃蛇-----kaine-----Daata : 2019 / 1 / 16     模式:正常模式                  分数:" + std::to_string(score); break;
		case 2:title = "title 催眠贪吃蛇-----kaine-----Daata : 2019 / 1 / 16     模式:困难模式                  分数:" + std::to_string(score); break;
		case 3: title = "title 催眠贪吃蛇-----kaine-----Daata : 2019 / 1 / 16     模式:变态模式                  分数:" + std::to_string(score); break;
		}
	    system(title.c_str());
		std::cout << '\a';
		addPoint(x, y);
		food.setFood();
	}
	else
	{
		addPoint(x, y);
		delPoint();
		if (isRool == true)
		{
			wall.setWall(x, y, '#');
			isRool = false;
		}

	}
	return true;
}
