#ifndef _STATUS_H_
#define _STATUS_H_

typedef struct
{
	Widget widget;
	short x;
	short y;
	short n;
	int degree;
	int color;
	
	int temp_int;
	short temp_short;
} Robot_status;

void init_status(Widget w, void *data);
int update_status(Robot_status *status);

Robot_status calc_statusition(Robot_status *status);

#endif