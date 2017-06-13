#ifndef _STATUS_H_
#define _STATUS_H_

typedef enum {
	false,
	true,
} bool;

typedef struct
{
	Widget widget;
	short x;
	short y;
	short n;
	int degree;
	int color;
	bool draw;

	int temp_int;
	short temp_short;
} Robot_status;

void init_status(Widget w, void *data);
int update_status(Robot_status *status);

Robot_status calc_position(Robot_status *status);

#endif