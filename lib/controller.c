#include <libsx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "status.h"

#include "controller.h"

void robot_quit(Widget w, void *data)
{
	exit(0);
}

void robot_forward(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	Robot_status status2;

	SetDrawArea(status->widget);
	status2 = calc_position(status);
	if (status->draw == true)
	{
		DrawLine(status->x, status->y, status2.x, status2.y);
	}
	update_status(status);
}

void robot_backward(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	Robot_status status2;

	SetDrawArea(status->widget);
	status->degree = status->degree - 180;
	status2 = calc_position(status);
	if (status->draw)
	{
		DrawLine(status->x, status->y, status2.x, status2.y);
	}
	update_status(status);
	status->degree = status->degree + 180;
}

void robot_turn_right(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	status->degree += 45;
}

void robot_turn_left(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	status->degree -= 45;
}

void robot_reset(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	SetDrawArea(status->widget);
	ClearDrawArea();
	init_status(status->widget, status);
}

void robot_draw(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	if (GetToggleState(w))
	{
		status->draw = true;
	}
	else
	{
		status->draw = false;
	}
}

void robot_set_color_black(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	SetDrawArea(status->widget);
	if (GetToggleState(w))
	{
		status->color = BLACK;
		SetColor(status->color);
	}
}
void robot_set_color_white(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	SetDrawArea(status->widget);
	if (GetToggleState(w))
	{
		status->color = WHITE;
		SetColor(status->color);
	}
}
void robot_set_color_green(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	SetDrawArea(status->widget);
	if (GetToggleState(w))
	{
		status->color = GREEN;
		SetColor(status->color);
	}
}
void robot_set_color_red(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	SetDrawArea(status->widget);
	if (GetToggleState(w))
	{
		status->color = RED;
		SetColor(status->color);
	}
}
void robot_set_color_blue(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	SetDrawArea(status->widget);
	if (GetToggleState(w))
	{
		status->color = BLUE;
		SetColor(status->color);
	}
}
void robot_set_color_yellow(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	SetDrawArea(status->widget);
	if (GetToggleState(w))
	{
		status->color = YELLOW;
		SetColor(status->color);
	}
}