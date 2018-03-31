/*
 * Vector.h
 *
 *  Created on: May 3, 2017
 *      Author: xuyimin
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <cmath>

#include "Math.h"

class Vector
{
public:
	Vector();
	Vector(double xx,double yy,double zz);

	~Vector();

	Vector operator+(const Vector& v) const;
	Vector& operator+=(const Vector& v);
	Vector operator*(double s) const;
	Vector& operator*=(double s);
	Vector operator/(double s) const;
	Vector& operator/=(double s);
	Vector operator-() const;
	double Length2() const;

	double x,y,z;
};

inline Vector operator*(double s,const Vector& v)
{
	return Vector(v.x*s,v.y*s,v.z*s);
}
inline double Dot(const Vector& v1,const Vector& v2)
{
	return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}
inline Vector Cross(const Vector& v1,const Vector& v2)
{
	return Vector(v1.y*v2.z-v1.z*v2.y,
			v1.z*v2.x-v1.x*v2.z,
			v1.x*v2.y-v1.y*v2.x);
}
inline Vector Normalize(const Vector& v)
{
	return v/std::sqrt(v.Length2());
}
inline bool operator==(const Vector& v1,const Vector& v2)
{
	return std::sqrt((-v1+v2).Length2())<0.00000001L;
}
#endif /* VECTOR_H_ */
