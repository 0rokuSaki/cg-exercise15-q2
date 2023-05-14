/*****************************************************************//**
 * \file   WcPoint3D.cpp
 * \brief  Function definitions for class WcPoint3D.
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

#include "WcPoint3D.h"

WcPoint3D::WcPoint3D() :
	_x(0.0), _y(0.0), _z(0.0)
{
}


WcPoint3D::WcPoint3D(GLdouble x, GLdouble y, GLdouble z) :
	_x(x), _y(y), _z(z)
{
}


GLdouble WcPoint3D::getX() const
{
	return _x;
}


GLdouble WcPoint3D::getY() const
{
	return _y;
}


GLdouble WcPoint3D::getZ() const
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


WcPoint3D WcPoint3D::operator*(const GLdouble val) const
{
	return WcPoint3D(val * _x, val * _y, val * _z);
}


WcPoint3D WcPoint3D::operator+(const WcPoint3D& other) const
{
	return WcPoint3D(_x + other._x, _y + other._y, _z + other._z);
}
