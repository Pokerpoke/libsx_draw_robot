#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <string.h>

#include "status.h"
#include "controller.h"

// enum Commands
// {
// 	FD,
// 	BK,
// 	COLOR,
// 	DRAW,
// 	UNDRAW,
// };

void robot_file(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	char *path = "robot.lg";
	char *cmd;
	const char *param;
	int i = 0;
	FILE *fp = fopen(path, "r");
	char str[101];

	init_status(status->widget, status);
	status->draw = false;
	ClearDrawArea();

	if (fp == NULL)
	{
		perror("File not open.");
	}
	else
	{
		while (fgets(str, 101, fp) != NULL)
		{
			cmd = strtok(str, " ");
			if ((strcmp(cmd, "FD")) == 0)
			{
				if ((param = strtok(NULL, " ")) != NULL)
				{
					status->n = atoi(param);
					robot_forward(status->widget, status);
				}
				else
				{
					printf("Something wrong in file.");
				}
			}
			else if (strcmp(cmd, "BK") == 0)
			{
				if ((param = strtok(NULL, " ")) != NULL)
				{
					status->n = atoi(param);
					robot_backward(status->widget, status);
				}
				else
				{
					printf("Something wrong in file.");
				}
			}
			else if (strcmp(cmd, "TR") == 0)
			{
				if ((param = strtok(NULL, " ")) != NULL)
				{
					status->degree += atoi(param);
				}
				else
				{
					printf("Something wrong in file.");
				}
			}
			else if (strcmp(cmd, "TL") == 0)
			{
				if ((param = strtok(NULL, " ")) != NULL)
				{
					status->degree -= atoi(param);
				}
				else
				{
					printf("Something wrong in file.");
				}
			}
			else if (strcmp(cmd, "DRAW\n") == 0)
			{
				status->draw = true;
			}
			else if (strcmp(cmd, "UNDRAW\n") == 0)
			{
				status->draw = false;
			}
			else if (strcmp(cmd, "COLOR") == 0)
			{
				if ((param = strtok(NULL, " ")) != NULL)
				{
					if (strcmp(param, "BLACK\n") == 0)
					{
						SetDrawArea(status->widget);
						status->color = BLACK;
						SetColor(status->color);
					}
					else if (strcmp(param, "WHITE\n") == 0)
					{
						SetDrawArea(status->widget);
						status->color = WHITE;
						SetColor(status->color);
					}
					else if (strcmp(param, "GREEN\n") == 0)
					{
						SetDrawArea(status->widget);
						status->color = GREEN;
						SetColor(status->color);
					}
					else if (strcmp(param, "RED\n") == 0)
					{
						SetDrawArea(status->widget);
						status->color = RED;
						SetColor(status->color);
					}
					else if (strcmp(param, "BLUE\n") == 0)
					{
						SetDrawArea(status->widget);
						status->color = BLUE;
						SetColor(status->color);
					}
					else if (strcmp(param, "YELLOW\n") == 0)
					{
						SetDrawArea(status->widget);
						status->color = YELLOW;
						SetColor(status->color);
					}
					else
					{
						SetDrawArea(status->widget);
						status->color = BLACK;
						SetColor(status->color);
					}
				}
				else
				{
					printf("Something wrong in file.");
				}
			}
		}
	}
	fclose(fp);
}
