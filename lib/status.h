#ifndef _STATUS_H_
#define _STATUS_H_

typedef enum {
	false,
	true,
} bool;

typedef struct
{
	Widget widget;
	int x;
	int y;
	int n;
	int degree;
	int color;
	bool draw;

	int temp_int;
} Robot_status;

void init_status(Widget w, void *data);
int update_status(Robot_status *status);

Robot_status calc_position(Robot_status *status);

#endif