#include <libsx.h>
#include <math.h>

#include "position.h"

#define PI 3.14159

int init_position(Robot_position *pos)
{
	pos->x = 0;
	pos->y = 0;
	pos->degree = 0;
	// pos->n = 0;

	return 0;
}

int update_position(Robot_position *pos)
{
	pos->x = pos->x + (short)(pos->n * cos((double)(pos->degree * PI / 180)));
	pos->y = pos->y + (short)(pos->n * sin((double)(pos->degree * PI / 180)));

	//如果坐标小于0好像会画不会来
	if (pos->x < 0)
	{
		pos->x = 0;
	}
	if (pos->y < 0)
	{
		pos->y = 0;
	}

	return 0;
}

Robot_position calc_position(Robot_position *pos)
{
	Robot_position pos2;

	pos2.x = pos->x + (short)(pos->n * cos((double)(pos->degree * PI / 180)));
	pos2.y = pos->y + (short)(pos->n * sin((double)(pos->degree * PI / 180)));
	//如果坐标小于0好像会画不会来
	if (pos2.x < 0)
	{
		pos2.x = 0;
	}
	if (pos2.y < 0)
	{
		pos2.y = 0;
	}

	return pos2;
}