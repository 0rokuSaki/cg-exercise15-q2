#pragma once
#include <GL/glut.h>


class WcPoint3D
{
private:
	GLdouble _x;
	GLdouble _y;
	GLdouble _z;

public:
	WcPoint3D();
	WcPoint3D(GLdouble x, GLdouble y, GLdouble z);
	GLdouble getX();
	GLdouble getY();
	GLdouble getZ();
	void setX(GLdouble x);
	void setY(GLdouble y);
	void setZ(GLdouble z);
};
