#pragma once
#include "Vector.h"

struct Particle
{
	Vector mCoordinate, mVelocity, mAcceleration;
	double mMass;
	Particle(double mass, Vector coordinate, Vector velocity = Vector(0, 0, 0), Vector accceleration = Vector(0, 0, 0)) :mMass(mass), mCoordinate(coordinate), mVelocity(velocity), mAcceleration(accceleration)
	{
	}
};
