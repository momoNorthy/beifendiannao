#include "pch.h"
#include "Wall.h"
#include <iostream>

void Wall::initWall()
{
	for(size_t i=0;i!=ROW;++i)
	{
		for (size_t t = 0; t != COL; ++t)
		{
			if(i==0||t==0||i==ROW-1||t==COL-1)
			{
				gameArray[i][t] = '*';
			}else
			{
				gameArray[i][t] = ' ';
			}
		}
	}
}

void Wall::drawWall()
{
	for (size_t i = 0; i != ROW; ++i)
	{
		for (size_t t = 0; t != COL; ++t)
		{
			std::cout << gameArray[i][t]<<' ';
		}
		std::cout << std::endl;
	}
}

void Wall::setWall(size_t x, size_t y, char c)
{
	gameArray[x][y] = c;
	gotoxy(y*2, x);
	std::cout << c;
}

char Wall::getWall(size_t x, size_t y)
{
	return gameArray[x][y];
}


