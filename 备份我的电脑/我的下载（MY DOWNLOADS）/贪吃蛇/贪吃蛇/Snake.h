#pragma once
#include "Wall.h"
#include "Food.h"

class Snake
{
public:
	Snake(Wall &wall,Food &food,int mode) :pHead(nullptr),wall(wall),food(food),mode(mode) {};
	enum{UP='w',DOWN='s',LEFT='a',RIGHT='d' };
	struct Point
	{
		int x;
		int y;
		Point *next;
	};
	//��ʼ��
	void initSnake();
	//���ٽڵ�
	void destroyPoint();
	
	void addPoint(int x, int y);

	void delPoint();

	bool  move(char key);
	Point *pHead;

	Wall &wall;

	Food &food;

	char lastKey;

	bool  isRool=false;

	int score = 0;

	int mode;



};

