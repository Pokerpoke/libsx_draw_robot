#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

void quit(Widget w, void *data);
void draw_stuff(Widget w, int width, int height, void *data);
void robot_forward(Widget w, Robot_position pos, short distance, void *data);

#endif
