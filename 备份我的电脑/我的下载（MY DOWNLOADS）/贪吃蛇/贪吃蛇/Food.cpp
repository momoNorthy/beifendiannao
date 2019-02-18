#include "pch.h"
#include "Food.h"
#include <random>
#include <iostream>
#include <ctime>
using namespace  std;

void Food::setFood()
{
  static  uniform_int_distribution<unsigned>u(1, wall.ROW);
  static default_random_engine e;
	do
	{
		foodX = u(e);
		foodY = u(e);
	} while (wall.getWall(foodX, foodY) != ' ');
	wall.setWall(++foodX, foodY, '#');

	//cout << foodX << "   " << foodY;
	
}
