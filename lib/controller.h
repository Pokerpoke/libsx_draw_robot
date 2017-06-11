#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

void quit(Widget w, void *data);
void draw_stuff(Widget w, int width, int height, void *data);
void robot_forward(Widget w, void *data);
void robot_backward(Widget w, void *data);
void robot_turn_right(Widget w, void *data);
void robot_turn_left(Widget w, void *data);
void robot_reset(Widget w,void *data);

#endif
