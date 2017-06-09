#include <libsx.h>
#include <stdio.h>
#include <stdlib.h>

#include "callbacks.h"

void quit(Widget w, void *data)
{
	exit(0);
}

void draw_stuff(Widget w, int width, int height, void *data)
{
  ClearDrawArea();
  DrawLine(0,0, width, height);   
}