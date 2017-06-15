#include "robot.h"

int main(int argc, char **argv)
{
	Widget convas, file, blank[5], input_command, command;
	// 控制控件
	Widget controller_forward, controller_turn_left, controller_turn_right, controller_backward, controller_draw, controller_reset, controller_quit;
	// 颜色控件
	Widget color_black, color_white, color_green, color_red, color_blue, color_yellow;
	// 总体布局
	Widget convas_form, controller_form, color_form, file_form;

	Robot_status status;

	// init_status(&status);
	// status.degree = 0;
	// status.n = 10;

	argc = OpenDisplay(argc, argv);
	if (argc == 0) /* woops, couldn't get started */
		exit(5);

	convas_form = MakeForm(TOP_LEVEL_FORM);
	//画布
	convas = MakeDrawArea(500, 500, NULL, NULL);
	init_status(convas, &status);

	controller_form = MakeForm(TOP_LEVEL_FORM);
	SetWidgetPos(controller_form, PLACE_RIGHT, convas_form, NO_CARE, NULL);
	// 控制按钮
	blank[0] = MakeLabel("        ");
	// 前进
	controller_forward = MakeButton("FORWARD", robot_forward, &status);
	blank[1] = MakeLabel("      ");
	// 左转
	controller_turn_left = MakeButton("TURN LEFT", robot_turn_left, &status);
	blank[2] = MakeLabel("      ");
	// 右转
	controller_turn_right = MakeButton("TURN RIGHT", robot_turn_right, &status);
	blank[3] = MakeLabel("       ");
	// 后退
	controller_backward = MakeButton("BACKWARD", robot_backward, &status);
	// 提笔,落笔
	controller_draw = MakeToggle("DRAW", TRUE, NULL, robot_draw, &status);
	blank[4] = MakeLabel("     ");
	// 复位
	controller_reset = MakeButton("RESET", robot_reset, &status);
	blank[5] = MakeLabel("     ");
	// 退出
	controller_quit = MakeButton("QUIT", robot_quit, NULL);

	SetWidgetPos(controller_forward, PLACE_RIGHT, blank[0], NO_CARE, NULL);
	SetWidgetPos(blank[1], PLACE_RIGHT, controller_forward, NO_CARE, NULL);
	SetWidgetPos(controller_turn_left, PLACE_UNDER, blank[0], NO_CARE, NULL);
	SetWidgetPos(blank[2], PLACE_RIGHT, controller_turn_left, PLACE_UNDER, controller_forward);
	SetWidgetPos(controller_turn_right, PLACE_RIGHT, blank[2], PLACE_UNDER, blank[1]);
	SetWidgetPos(blank[3], PLACE_UNDER, controller_turn_left, NO_CARE, NULL);
	SetWidgetPos(controller_backward, PLACE_RIGHT, blank[3], PLACE_UNDER, blank[2]);
	SetWidgetPos(blank[4], PLACE_RIGHT, controller_backward, PLACE_UNDER, controller_turn_right);
	SetWidgetPos(controller_draw, PLACE_UNDER, blank[3], NO_CARE, NULL);
	SetWidgetPos(blank[5], PLACE_RIGHT, controller_draw, PLACE_UNDER, controller_backward);
	SetWidgetPos(controller_reset, PLACE_UNDER, controller_draw, NO_CARE, NULL);
	SetWidgetPos(controller_quit, PLACE_RIGHT, controller_reset, PLACE_UNDER, blank[5]);

	color_form = MakeForm(TOP_LEVEL_FORM);
	SetWidgetPos(color_form, PLACE_RIGHT, convas_form, PLACE_UNDER, controller_form);
	color_black = MakeToggle("BLACK", TRUE, NULL, robot_set_color_black, &status);
	color_white = MakeToggle("WHITE", FALSE, color_black, robot_set_color_white, &status);
	color_green = MakeToggle("GREEN", FALSE, color_black, robot_set_color_green, &status);
	color_red = MakeToggle("RED", FALSE, color_black, robot_set_color_red, &status);
	color_blue = MakeToggle("BLUE", FALSE, color_black, robot_set_color_blue, &status);
	color_yellow = MakeToggle("YELLOW", FALSE, color_black, robot_set_color_yellow, &status);

	SetWidgetPos(color_black, NO_CARE, NULL, NO_CARE, NULL);
	SetWidgetPos(color_white, PLACE_UNDER, color_black, NO_CARE, NULL);
	SetWidgetPos(color_green, PLACE_UNDER, color_white, NO_CARE, NULL);
	SetWidgetPos(color_red, PLACE_UNDER, color_green, NO_CARE, NULL);
	SetWidgetPos(color_blue, PLACE_UNDER, color_red, NO_CARE, NULL);
	SetWidgetPos(color_yellow, PLACE_UNDER, color_blue, NO_CARE, NULL);

	file_form = MakeForm(TOP_LEVEL_FORM);
	SetWidgetPos(file_form, PLACE_RIGHT, convas_form, PLACE_UNDER, color_form);
	file = MakeButton("OPEN FILE", robot_file, &status);
	command = MakeButton("COMMAND", NULL, NULL);
	input_command = MakeStringEntry(NULL, 150, robot_command, &status);

	SetWidgetPos(input_command, PLACE_UNDER, file, NO_CARE, NULL);
	SetWidgetPos(command, PLACE_UNDER, input_command, NO_CARE, NULL);

	ShowDisplay();
	GetStandardColors();

	MainLoop();

	return 0;
}
