#pragma once
#include <set>
#include "Wall.h"

class Food
{
public:
	Food(Wall&wall) :wall(wall) {}
	int foodX;
	int foodY;
	Wall &wall;
	void setFood();
	
};

