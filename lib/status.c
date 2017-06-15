#include <stdio.h>
#include <libsx.h>
#include <math.h>

#include "status.h"

#define PI 3.14159

void init_status(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	status->x = 0;
	status->y = 0;
	status->degree = 0;
	status->n = 10;
	status->color = BLACK;

	status->draw = true;
}

void update_label(Robot_status *status)
{
	if (status->has_label)
	{
		char *tmp_color;
		if (status->color == BLACK)
		{
			tmp_color = "black";
		}
		else if (status->color == WHITE)
		{
			tmp_color = "white";
		}
		else if (status->color == BLUE)
		{
			tmp_color = "blue";
		}
		else if (status->color == RED)
		{
			tmp_color = "red";
		}
		else if (status->color == YELLOW)
		{
			tmp_color = "yellow";
		}
		else if (status->color == GREEN)
		{
			tmp_color = "green";
		}

		char tmp[100];
		sprintf(tmp, "position:(%d,%d)\ndegree:%d\nn:%d\ncolor:%s", status->x, status->y, status->degree, status->n, tmp_color);
		SetLabel(status->label, tmp);
	}
}

int update_status(Robot_status *status)
{
	int w, h;
	GetDrawAreaSize(&w, &h);

	status->x = status->x + (int)(status->n * cos((double)(status->degree * PI / 180)));
	status->y = status->y + (int)(status->n * sin((double)(status->degree * PI / 180)));

	//如果坐标小于0好像会画不出来
	if (status->x < 0)
	{
		status->x = 0;
	}
	if (status->y < 0)
	{
		status->y = 0;
	}
	if (status->x > w)
	{
		status->x = w;
	}
	if (status->y > h)
	{
		status->y = h;
	}

	update_label(status);

	return 0;
}

Robot_status calc_position(Robot_status *status)
{
	Robot_status status2;

	status2.x = status->x + (short)(status->n * cos((double)(status->degree * PI / 180)));
	status2.y = status->y + (short)(status->n * sin((double)(status->degree * PI / 180)));

	//如果坐标小于0好像会画不出来
	if (status2.x < 0)
	{
		status2.x = 0;
	}
	if (status2.y < 0)
	{
		status2.y = 0;
	}

	return status2;
}