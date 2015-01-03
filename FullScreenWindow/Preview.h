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

private:
	// Size of the preview, 0,0 is in the top left corner
	int left,top,right,bottom;


	QGraphicsView* preview;
	QGraphicsScene* scene;
	QBrush wallpaperBrush;
	QPen borderPen;

	QGraphicsRectItem* screen;
};

