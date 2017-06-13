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

	status->draw = true;
}

int update_status(Robot_status *status)
{
	status->x = status->x + (short)(status->n * cos((double)(status->degree * PI / 180)));
	status->y = status->y + (short)(status->n * sin((double)(status->degree * PI / 180)));

	//如果坐标小于0好像会画不出来
	if (status->x < 0)
	{
		status->x = 0;
	}
	if (status->y < 0)
	{
		status->y = 0;
	}

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