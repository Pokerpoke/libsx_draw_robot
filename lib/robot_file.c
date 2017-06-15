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

void robot_get_command(char *str, void *data)
{
	Robot_status *status = (Robot_status *)data;
	char *cmd, *param;

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
	else if (strcmp(cmd, "DRAW\n") == 0 || strcmp(cmd, "DRAW") == 0)
	{
		status->draw = true;
	}
	else if (strcmp(cmd, "UNDRAW\n") == 0 || strcmp(cmd, "UNDRAW") == 0)
	{
		status->draw = false;
	}
	else if (strcmp(cmd, "COLOR") == 0)
	{
		if ((param = strtok(NULL, "\n")) != NULL)
		{
			if (strcmp(param, "BLACK") == 0)
			{
				SetDrawArea(status->widget);
				status->color = BLACK;
				SetColor(status->color);
			}
			else if (strcmp(param, "WHITE") == 0)
			{
				SetDrawArea(status->widget);
				status->color = WHITE;
				SetColor(status->color);
			}
			else if (strcmp(param, "GREEN") == 0)
			{
				SetDrawArea(status->widget);
				status->color = GREEN;
				SetColor(status->color);
			}
			else if (strcmp(param, "RED") == 0)
			{
				SetDrawArea(status->widget);
				status->color = RED;
				SetColor(status->color);
			}
			else if (strcmp(param, "BLUE") == 0)
			{
				SetDrawArea(status->widget);
				status->color = BLUE;
				SetColor(status->color);
			}
			else if (strcmp(param, "YELLOW") == 0)
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

void robot_file(Widget w, void *data)
{
	Robot_status *status = (Robot_status *)data;

	char *path =GetFile("Input file",NULL,NULL,NULL);
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
			robot_get_command(str, status);
		}
	}
	update_label(status);
	fclose(fp);
}

void robot_command(Widget w, char *text, void *data)
{
	Robot_status *status = (Robot_status *)data;

	robot_get_command(text, status);
	update_label(status);
	SetStringEntry(w, "");
}
