#include <stdio.h>

#include "ComplexShape.h"
#include "Circle.h"
#include "Rect.h"
#include "Point.h"

void draw(Shape &s, Point &start, Point &end, int resX, int resY)
{
	float diffX = (end.getX() - start.getX()) / resX;
	float diffY = (end.getY() - start.getY()) / resY;
	printf("diff = %f;%f\n\n", diffX, diffY);

	printf("-----------------------------------------------------------------------\n");
	for(float y = start.getY(); y >= end.getY(); y += diffY)
	{
		for(float x = start.getX(); x <= end.getX(); x += diffX)
		{
			Point p(x, y);
			if(s.isIn(p))
				printf("X");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("-----------------------------------------------------------------------\n");
}

int main(int argc, char *argv[])
{
	printf("main: arrived\n");

	Circle c(3);
	Rect r(14, 2);
	ComplexShape cs(&c, &r, SYMMETRIC_DIFF);

	Point r_pos(-4, 2);
	r.setPosition(r_pos);

	Point c_pos(0, -1);
	c.setPosition(c_pos);

	Point cs_pos(1, -3);
	cs.setPosition(cs_pos);

	Point start(-10, 5);
	Point end(10, -5);

	draw(cs, start, end, 40, 20);

	return 0;
}