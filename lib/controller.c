#include <libsx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "position.h"

#include "controller.h"

void quit(Widget w, void *data)
{
	exit(0);
}

void robot_forward(Widget w, void *data)
{
	Robot_position *pos = (Robot_position *)data;

	Robot_position pos2;

	SetDrawArea(w);
	pos2 = calc_position(pos);
	DrawLine(pos->x, pos->y, pos2.x, pos2.y);
	update_position(pos);
}

void robot_backward(Widget w, void *data)
{
	Robot_position *pos = (Robot_position *)data;

	Robot_position pos2;

	SetDrawArea(w);
	pos->degree = pos->degree - 180;
	pos2 = calc_position(pos);
	DrawLine(pos->x, pos->y, pos2.x, pos2.y);
	update_position(pos);
	pos->degree = pos->degree + 180;
}

void robot_turn_right(Widget w, void *data)
{
	Robot_position *pos = (Robot_position *)data;

	pos->degree += 45;
}

void robot_turn_left(Widget w, void *data)
{
	Robot_position *pos = (Robot_position *)data;

	pos->degree -= 45;
}

void robot_reset(Widget w, void *data)
{
	Robot_position *pos = (Robot_position *)data;

	SetDrawArea(w);
	ClearDrawArea();
	init_position(pos);
}