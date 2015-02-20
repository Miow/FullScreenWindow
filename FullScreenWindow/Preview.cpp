#include "stdafx.h"
#include "Preview.h"

Preview::Preview(QGraphicsView* previewWidget)
{
	preview = previewWidget;
	preview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	preview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// Getting the graphicsView's size
	QSize size = preview->geometry().size();
	QMargins margin = preview->contentsMargins();
	gX = 0;
	gY = 0;
	gWidth = size.width() - (margin.left() + margin.right()) - 1;
	gHeight = size.height() - (margin.top() + margin.bottom()) - 1;


	scene = new QGraphicsScene();
	scene->setSceneRect(gX, gY, gWidth, gHeight);
	previewWidget->setScene(scene);
	
	cBorderWidth = gHeight / 25;
	cTaskBarHeight = gHeight / 10;
	cTaskBarButtonSize = cTaskBarHeight * 2 / 3;
	cWindowBorderWidth = gHeight / 75;
	cWindowTitleBarHeight = gHeight / 20;
	cWindowMenuBarHeight = gHeight / 25;


	borderBrush = QBrush(Qt::black);
	screenBrush = QBrush(QColor(0, 150, 255, 255));
	taskBarBrush = QBrush(QColor(50, 200, 255, 200));
	taskBarButtonBrush = QBrush(QColor(255, 255, 255, 255));
	windowContentBrush = QBrush(QColor(250, 250, 250, 255));
	windowTitleBarBrush = QBrush(QColor(50, 200, 255, 255));
	windowBackgroundBrush = QBrush(QColor(230, 230, 230, 255));
	
	invisiblePen = QPen(Qt::transparent);
	invisiblePen.setWidth(0);

	border = scene->addRect(0, 0, 0, 0, invisiblePen, borderBrush);
	screen = scene->addRect(0, 0, 0, 0, invisiblePen, screenBrush);
	taskBar = scene->addRect(0, 0, 0, 0, invisiblePen, taskBarBrush);
	taskBarButton = scene->addRect(0, 0, 0, 0, invisiblePen, taskBarButtonBrush);
	windowTitleBar = scene->addRect(0, 0, 0, 0, invisiblePen, windowTitleBarBrush);
	windowBackground = scene->addRect(0, 0, 0, 0, invisiblePen, windowBackgroundBrush);
	windowContent = scene->addRect(0, 0, 0, 0, invisiblePen, windowContentBrush);
	
	border->setZValue(1);
	screen->setZValue(2);
	taskBar->setZValue(3);
	taskBarButton->setZValue(4);
	windowTitleBar->setZValue(10);
	windowBackground->setZValue(11);
	windowContent->setZValue(12);
}


Preview::~Preview()
{
	delete scene;
}

void Preview::defaultView(Monitor* mon)
{
	int width = 1920;
	int height = 1080;

	if (mon != NULL)
	{
		width = mon->width;
		height = mon->height;
	}

	drawScreen(width, height);
	drawWindow(width / 5, height / 5, width / 2.5, height / 2, false, false);
}

void Preview::update(Profile* pro, Monitor* mon)
{
	if (pro->getName() == PROFILE_DEFAULT_DISABLED)
	{
		defaultView(mon);
	}
	else
	{
		drawScreen(mon->width, mon->height);

		int xpos, ypos, width, height;
		if (pro->isSizeRelative)
		{
			width = mon->width + pro->width;
			height = mon->height + pro->height;
		}
		else
		{
			width = pro->width;
			height = pro->height;
		}
		xpos = pro->xpos;
		ypos = pro->ypos;

		drawWindow(xpos, ypos, width, height, pro->isTitleBarHidden, pro->isSizeRelative && pro->isTaskBarShown);
	}
}


void Preview::drawScreen(double width, double height)
{
	screenWidth = width;
	screenHeight = height;

	double ratio = width / height;
	// if the screen is wider than the preview
	if (ratio > (gWidth / gHeight))
	{
		sWidth = gWidth;
		sHeight = gWidth * ratio;
		sX = (gWidth - sWidth) / 2;
		sY = (gHeight - sHeight) / 2;
	}
	else
	{
		sWidth = gHeight * ratio;
		sHeight = gHeight;
		sX = (gWidth - sWidth) / 2;
		sY = (gHeight - sHeight) / 2;
		
	}


	// Drawing the border
	border->setRect(sX, sY, sWidth, sHeight);

	// Updating screen rectangle with border
	sX = sX + cBorderWidth;
	sY = sY + cBorderWidth;
	sWidth = sWidth - cBorderWidth * 2;
	sHeight = sHeight - cBorderWidth * 2;

	// Drawing the screen
	screen->setRect(sX, sY, sWidth, sHeight);

	// Taskbar
	taskBar->setRect(sX, sY + sHeight - cTaskBarHeight, sWidth, cTaskBarHeight);

	taskBarButton->setRect(
		sX + (cTaskBarHeight - cTaskBarButtonSize) / 2,
		sY + sHeight - cTaskBarHeight + (cTaskBarHeight - cTaskBarButtonSize) / 2,
		cTaskBarButtonSize,
		cTaskBarButtonSize
		);
}

void Preview::drawWindow(double xpos, double ypos, double width, double height, bool isTitleBarHidden, bool isTaskBarShown)
{
	wX = xpos / screenWidth * sWidth + sX;
	wY = ypos / screenHeight * sHeight + sY;
	wWidth = width / screenWidth * sWidth;
	wHeight = height / screenHeight * sHeight;

	if (isTaskBarShown)
	{
		wHeight -= cTaskBarHeight;
	}

	windowTitleBar->setRect(
		wX,
		wY,
		wWidth,
		wHeight
		);

	if (isTitleBarHidden)
	{
		windowBackground->setRect(
			wX,
			wY,
			wWidth,
			wHeight
			);

		windowContent->setRect(
			wX,
			wY + cWindowMenuBarHeight,
			wWidth,
			wHeight - cWindowMenuBarHeight
			);

	}
	else
	{
		windowBackground->setRect(
			wX + cWindowBorderWidth,
			wY + cWindowTitleBarHeight,
			wWidth - cWindowBorderWidth * 2,
			wHeight - cWindowTitleBarHeight - cWindowBorderWidth
			);
		
		windowContent->setRect(
			wX + cWindowBorderWidth,
			wY + cWindowTitleBarHeight + cWindowMenuBarHeight,
			wWidth - cWindowBorderWidth * 2,
			wHeight - cWindowBorderWidth - cWindowTitleBarHeight - cWindowMenuBarHeight
			);
		
	}
	
	
}