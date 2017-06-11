#include <libsx.h>
#include <math.h>

#include "position.h"

#define PI 3.14159

int init_position(Robot_position pos)
{
	pos.x = 0;
	pos.y = 0;
	pos.degree = 0;
	return 0;
}

Robot_position calc_position(Robot_position pos, short distance)
{
	Robot_position pos2;
	pos2.x = pos.x + (short)(distance * cos((double)(pos.degree * PI / 180)));
	pos2.y = pos.y + (short)(distance * sin((double)(pos.degree * PI / 180)));
	return pos2;
}