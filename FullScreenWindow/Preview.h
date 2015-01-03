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
	void drawScreen(int width, int height);
	void drawWindow(int xpos, int ypos, int width, int height, int hasTitleBar);

private:
	// Size of the preview, 0,0 is in the top left corner
	int gX, gY, gWidth, gHeight;
	int sX, sY, sWidth, sHeight;

	int cBorderWidth,
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

