#include <libsx.h>
#include <math.h>

#include "position.h"

#define PI 3.14159

int init_position(Robot_position *pos)
{
	memset(&pos, 0, sizeof(pos));
	return 0;
}

int update_position(Robot_position *pos)
{
	*pos = calc_position(pos);
	return 0;
}

Robot_position calc_position(Robot_position *pos)
{
	Robot_position pos2;

	pos2.x = pos->x + (short)(pos->n * cos((double)(pos->degree * PI / 180)));
	pos2.y = pos->y + (short)(pos->n * sin((double)(pos->degree * PI / 180)));
	return pos2;
}