#pragma once

#include <Windows.h>
class Wall
{
public:
	enum
	{
		ROW = 40,
		COL=40		
	};
	void initWall();
	void drawWall();
	void setWall(size_t x,size_t y,char c);
	char getWall(size_t x,size_t y);
	void gotoxy(int x, int y) {
		COORD c;
		c.X = x - 1;
		c.Y = y - 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}

private:

	char gameArray[ROW][COL];

};

