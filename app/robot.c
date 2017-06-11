#include "robot.h"

int main(int argc, char **argv)
{
	Widget w[8];
	Widget convas, blank[5];
	Widget convas_form, controller_form;

	Robot_position pos;

	init_position(&pos);
	pos.degree = 45;
	pos.n = 10;

	argc = OpenDisplay(argc, argv);
	if (argc == 0) /* woops, couldn't get started */
		exit(5);

	convas_form = MakeForm(TOP_LEVEL_FORM);
	//画布
	MakeDrawArea(500, 500, NULL, NULL);

	controller_form = MakeForm(TOP_LEVEL_FORM);
	SetWidgetPos(controller_form, PLACE_RIGHT, convas_form, NO_CARE, NULL);
	//控制按钮
	blank[0] = MakeLabel("      ");

	//前进
	w[0] = MakeButton("AVANCE", robot_forward, &pos);
	SetWidgetPos(w[0], PLACE_RIGHT, blank[0], NO_CARE, NULL);

	blank[1] = MakeLabel("      ");
	SetWidgetPos(blank[1], PLACE_RIGHT, w[0], NO_CARE, NULL);

	//左转
	w[1] = MakeButton("GAUCHE", NULL, NULL);
	SetWidgetPos(w[1], PLACE_UNDER, blank[0], NO_CARE, NULL);

	blank[2] = MakeLabel("      ");
	SetWidgetPos(blank[2], PLACE_RIGHT, w[1], PLACE_UNDER, w[0]);

	//右转
	w[2] = MakeButton("DROITE", NULL, NULL);
	SetWidgetPos(w[2], PLACE_RIGHT, blank[2], PLACE_UNDER, blank[1]);

	blank[3] = MakeLabel("      ");
	SetWidgetPos(blank[3], PLACE_UNDER, w[1], NO_CARE, NULL);

	//后退
	w[3] = MakeButton("RECULE", NULL, NULL);
	SetWidgetPos(w[3], PLACE_RIGHT, blank[3], PLACE_UNDER, blank[2]);

	//提笔
	w[4] = MakeButton("LEVE_CRAYON", NULL, NULL);
	SetWidgetPos(w[4], PLACE_UNDER, blank[3], NO_CARE, NULL);

	blank[4] = MakeLabel("     ");
	SetWidgetPos(blank[4], PLACE_RIGHT, w[3], PLACE_UNDER, w[2]);

	//落笔
	w[5] = MakeButton("BAISSE_CRAYON", NULL, NULL);
	SetWidgetPos(w[5], PLACE_RIGHT, w[4], PLACE_UNDER, blank[4]);

	//设置颜色
	w[6] = MakeButton("COULEUR", NULL, NULL);
	SetWidgetPos(w[6], PLACE_UNDER, w[5], NO_CARE, NULL);

	//复位
	w[7] = MakeButton("NETTOIE", NULL, NULL);
	SetWidgetPos(w[7], PLACE_UNDER, w[6], NO_CARE, NULL);

	blank[5] = MakeLabel("     ");
	SetWidgetPos(blank[5], PLACE_RIGHT, w[7], PLACE_UNDER, w[5]);

	//退出
	w[8] = MakeButton("QUIT", quit, NULL);
	SetWidgetPos(w[8], PLACE_RIGHT, w[7], PLACE_UNDER, blank[5]);

	ShowDisplay();
	GetStandardColors();

	MainLoop();

	return 0;
}
