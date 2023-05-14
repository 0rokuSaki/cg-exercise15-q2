#include "WcPoint3D.h"

WcPoint3D::WcPoint3D() :
	_x(0.0), _y(0.0), _z(0.0)
{
}

WcPoint3D::WcPoint3D(GLdouble x, GLdouble y, GLdouble z) :
	_x(x), _y(y), _z(z)
{
}

GLdouble WcPoint3D::getX()
{
	return _x;
}

GLdouble WcPoint3D::getY()
{
	return _y;
}

GLdouble WcPoint3D::getZ()
{
	return _z;
}

void WcPoint3D::setX(GLdouble x)
{
	_x = x;
}

void WcPoint3D::setY(GLdouble y)
{
	_y = y;
}

void WcPoint3D::setZ(GLdouble z)
{
	_z = z;
}
