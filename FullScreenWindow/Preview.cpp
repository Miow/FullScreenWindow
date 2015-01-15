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
}


Preview::~Preview()
{
	delete scene;
}

void Preview::defaultView()
{
	drawScreen(1920, 1080);
	drawWindow(400, 200, 800, 600, false, false);
}

void Preview::update(const Profile* pro)
{
	drawScreen(pro->mon->width, pro->mon->height);

	int xpos, ypos, width, height;
	if (pro->isSizeRelative)
	{
		width = pro->mon->width + pro->width;
		height = pro->mon->height + pro->height;
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
	border = scene->addRect(sX, sY, sWidth, sHeight, invisiblePen, borderBrush);
	border->setZValue(1);

	// Updating screen rectangle with border
	sX = sX + cBorderWidth;
	sY = sY + cBorderWidth;
	sWidth = sWidth - cBorderWidth * 2;
	sHeight = sHeight - cBorderWidth * 2;

	// Drawing the screen
	screen = scene->addRect(sX, sY, sWidth, sHeight, invisiblePen, screenBrush);
	screen->setZValue(2);

	// Taskbar
	taskBar = scene->addRect(sX, sY + sHeight - cTaskBarHeight, sWidth, cTaskBarHeight, invisiblePen, taskBarBrush);
	taskBar->setZValue(3);
	taskBarButton = scene->addRect(
		sX + (cTaskBarHeight - cTaskBarButtonSize) / 2,
		sY + sHeight - cTaskBarHeight + (cTaskBarHeight - cTaskBarButtonSize) / 2,
		cTaskBarButtonSize,
		cTaskBarButtonSize,
		invisiblePen, taskBarButtonBrush);
	taskBarButton->setZValue(3);
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

	if (isTitleBarHidden)
	{
		windowContent = scene->addRect(wX, wY, wWidth, wHeight, invisiblePen, windowContentBrush);
		windowContent->setZValue(12);
		windowBackground->setZValue(0);
		windowTitleBar->setZValue(0);
	}
	else
	{
		windowTitleBar = scene->addRect(wX, wY, wWidth, wHeight, invisiblePen, windowTitleBarBrush);
		windowTitleBar->setZValue(10);

		windowBackground = scene->addRect(
			wX + cWindowBorderWidth,
			wY + cWindowTitleBarHeight, wWidth - cWindowBorderWidth * 2,
			wHeight - cWindowTitleBarHeight - cWindowBorderWidth,
			invisiblePen, windowBackgroundBrush);
		windowBackground->setZValue(11); 
		
		windowContent = scene->addRect(
			wX + cWindowBorderWidth,
			wY + cWindowTitleBarHeight + cWindowMenuBarHeight,
			wWidth - cWindowBorderWidth * 2,
			wHeight - cWindowBorderWidth - cWindowTitleBarHeight - cWindowMenuBarHeight,
			invisiblePen, windowContentBrush);
		windowContent->setZValue(12);
		
	}
	
	
}