/*
 * Vector.cpp
 *
 *  Created on: May 3, 2017
 *      Author: xuyimin
 */


#include "Vector.h"

Vector::Vector():x(0),y(0),z(0)
{
}

Vector::Vector(double xx,double yy,double zz):x(xx),y(yy),z(zz)
{
}

Vector::~Vector()
{
}

Vector Vector::operator+(const Vector& v) const
{
	return Vector(x+v.x,y+v.y,z+v.z);
}

Vector& Vector::operator+=(const Vector& v)
{
	x+=v.x;
	y+=v.y;
	z+=v.z;
	return *this;
}

Vector Vector::operator*(double s) const
{
	return Vector(x*s,y*s,z*s);
}

Vector& Vector::operator*=(double s)
{
	x*=s;
	y*=s;
	z*=s;
	return *this;
}

Vector Vector::operator/(double s) const
{
	double inv=1/s;
	return Vector(x*inv,y*inv,z*inv);
}

Vector& Vector::operator/=(double s)
{
	double inv=1.f/s;
	x*=inv;
	y*=inv;
	z*=inv;
	return *this;
}

Vector Vector::operator-() const
{
	return Vector(-x,-y,-z);
}

double Vector::Length2() const
{
	return x*x+y*y+z*z;
}





