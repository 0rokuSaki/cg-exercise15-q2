/*****************************************************************//**
 * \file   WcPoint3D.h
 * \brief  Class declaration of WcPoint3D.
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

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
	GLdouble getX() const;
	GLdouble getY() const;
	GLdouble getZ() const;
	void setX(GLdouble x);
	void setY(GLdouble y);
	void setZ(GLdouble z);
	WcPoint3D operator*(const GLdouble val) const;
	WcPoint3D operator+(const WcPoint3D& other) const;
};
