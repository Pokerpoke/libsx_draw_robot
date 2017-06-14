#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

void robot_quit(Widget w, void *data);
void robot_forward(Widget w, void *data);
void robot_backward(Widget w, void *data);
void robot_turn_right(Widget w, void *data);
void robot_turn_left(Widget w, void *data);
void robot_reset(Widget w, void *data);
void robot_draw(Widget w, void *data);

// 设置颜色,好像没有传递Widget的名字的函数,不知道怎么用一个函数解决
// void robot_set_color(Widget w,void *data);
void robot_set_color_black(Widget w, void *data);
void robot_set_color_white(Widget w, void *data);
void robot_set_color_green(Widget w, void *data);
void robot_set_color_red(Widget w, void *data);
void robot_set_color_blue(Widget w, void *data);
void robot_set_color_yellow(Widget w, void *data);

#endif
