#ifndef _POSITION_H_
#define _POSITION_H_

typedef struct
{
	short x;
	short y;
	short n;
	int degree;
} Robot_position;

int init_position(Robot_position *pos);
int update_position(Robot_position *pos);

Robot_position calc_position(Robot_position *pos);

#endif