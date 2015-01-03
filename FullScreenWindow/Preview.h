#pragma once
#include "main.h"

#include "Profile.h"
#include "Monitor.h"

#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsItem>


class Preview
{
public:
	Preview(QGraphicsView* preview);
	~Preview();

	void init();
	void update(const Monitor mon, const Profile pro);
	void drawScreen(double width, double height);
	void drawWindow(double xpos, double ypos, double width, double height, bool isTitleBarHidden, double screenWidth, double screenHeight);

private:
	// Size of the preview, 0,0 is in the top left corner
	double gX, gY, gWidth, gHeight;
	double sX, sY, sWidth, sHeight;
	double wX, wY, wWidth, wHeight;

	double cBorderWidth,
		cTaskBarHeight, cTaskBarButtonSize,
		cWindowTitleBarHeight, cWindowMenuBarHeight;

	QGraphicsView* preview;
	QGraphicsScene* scene;

	QPen invisiblePen;

	QBrush borderBrush,
		screenBrush,
		taskBarBrush, taskBarButtonBrush,
		windowBrush,
		windowTitleBarBrush,
		windowMenuBarBrush;

	QGraphicsRectItem
		*border,
		*screen,
		*taskBar, *taskBarButton,
		*window,
		*windowTitleBar,
		*windowMenuBar;
};

