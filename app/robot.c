#include "robot.h"

int main(int argc, char **argv)
{
	Widget w[8];
	Widget color_black, color_white, color_green, color_red, color_blue, color_yellow;
	Widget convas, blank[5];
	Widget convas_form, controller_form, color_form;

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
	blank[0] = MakeLabel("      ");
	// 前进
	w[0] = MakeButton("AVANCE", robot_forward, &status);
	blank[1] = MakeLabel("      ");
	// 左转
	w[1] = MakeButton("GAUCHE", robot_turn_left, &status);
	blank[2] = MakeLabel("      ");
	// 右转
	w[2] = MakeButton("DROITE", robot_turn_right, &status);
	blank[3] = MakeLabel("      ");
	// 后退
	w[3] = MakeButton("RECULE", robot_backward, &status);
	// 提笔
	w[4] = MakeButton("LEVE_CRAYON", NULL, NULL);
	blank[4] = MakeLabel("     ");
	// 落笔
	w[5] = MakeButton("BAISSE_CRAYON", NULL, NULL);
	// 设置颜色
	w[6] = MakeButton("COULEUR", NULL, NULL);
	// 复位
	w[7] = MakeButton("NETTOIE", robot_reset, &status);
	blank[5] = MakeLabel("     ");
	// 退出
	w[8] = MakeButton("QUIT", quit, NULL);

	SetWidgetPos(w[0], PLACE_RIGHT, blank[0], NO_CARE, NULL);
	SetWidgetPos(blank[1], PLACE_RIGHT, w[0], NO_CARE, NULL);
	SetWidgetPos(w[1], PLACE_UNDER, blank[0], NO_CARE, NULL);
	SetWidgetPos(blank[2], PLACE_RIGHT, w[1], PLACE_UNDER, w[0]);
	SetWidgetPos(w[2], PLACE_RIGHT, blank[2], PLACE_UNDER, blank[1]);
	SetWidgetPos(blank[3], PLACE_UNDER, w[1], NO_CARE, NULL);
	SetWidgetPos(w[3], PLACE_RIGHT, blank[3], PLACE_UNDER, blank[2]);
	SetWidgetPos(w[4], PLACE_UNDER, blank[3], NO_CARE, NULL);
	SetWidgetPos(blank[4], PLACE_RIGHT, w[3], PLACE_UNDER, w[2]);
	SetWidgetPos(w[5], PLACE_RIGHT, w[4], PLACE_UNDER, blank[4]);
	SetWidgetPos(w[6], PLACE_UNDER, w[5], NO_CARE, NULL);
	SetWidgetPos(w[7], PLACE_UNDER, w[6], NO_CARE, NULL);
	SetWidgetPos(blank[5], PLACE_RIGHT, w[7], PLACE_UNDER, w[5]);
	SetWidgetPos(w[8], PLACE_RIGHT, w[7], PLACE_UNDER, blank[5]);

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

	ShowDisplay();
	GetStandardColors();

	MainLoop();

	return 0;
}
