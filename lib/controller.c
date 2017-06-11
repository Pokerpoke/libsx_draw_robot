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

void robot_forward(Widget w, Robot_position pos, short distance, void *data)
{
  SetDrawArea(w);
  // ClearDrawArea();
  Robot_position pos2;
  pos.degree = 45;
  distance = 100;
  pos2 = calc_position(pos, distance);
  DrawLine(pos.x, pos.y, pos2.x, pos2.y);
}

void robot_backward(Widget w, int distance, void *data)
{
  SetDrawArea(w);
  ClearDrawArea();
  DrawLine(0, 0, 100, 100);
}