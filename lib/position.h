#ifndef _POSITION_H_
#define _POSITION_H_

typedef struct
{
	short x;
	short y;
	int degree;
}Robot_position;

int init_position(Robot_position pos);

Robot_position calc_position(Robot_position pos, short distance);

#endif